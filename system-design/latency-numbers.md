# Latency Numbers Every Programmer Should Know

**In one sentence:** A rough table of how long common operations take, so I can tell which part of a design is slow before I measure anything.

**Why it matters for low-latency code:** Every time a value moves from a register, to cache, to RAM, to disk, to the network, the cost grows by about 10x to 1000x. Fast code keeps hot data in cache and keeps disk and network calls off the critical path.

## The numbers (approximate, modern hardware)

| Operation                                   | Time           | In ns          | Feel                      |
| ------------------------------------------- | -------------- | -------------- | ------------------------- |
| L1 cache reference                          | 0.5–1 ns       | 1              | Instant                   |
| Branch mispredict                           | ~3–5 ns        | 5              |                           |
| L2 cache reference                          | ~4 ns          | 4              |                           |
| L3 cache reference                          | ~10–40 ns      | 20             |                           |
| Mutex lock/unlock (uncontended)             | ~15–25 ns      | 20             |                           |
| Main memory (RAM) reference                 | ~100 ns        | 100            | 100x slower than L1       |
| Compress 1 KB with a fast codec (Snappy/LZ4)| ~2 µs          | 2,000          |                           |
| Send 1 KB over a 10 Gbps network            | ~1 µs          | 1,000          |                           |
| Read 4 KB at random from an NVMe SSD        | ~20–100 µs     | 50,000         |                           |
| Read 1 MB sequentially from RAM             | ~3–10 µs       | 5,000          |                           |
| Round trip inside one datacenter            | ~500 µs        | 500,000        | Half a millisecond        |
| Read 1 MB sequentially from an SSD          | ~50–250 µs     | 200,000        |                           |
| Disk (HDD) seek                             | ~2–10 ms       | 10,000,000     | Avoid on hot paths        |
| Read 1 MB sequentially from an HDD          | ~1–5 ms        | 2,000,000      |                           |
| Round trip, same continent                  | ~20–50 ms      | 30,000,000     |                           |
| Round trip, California ↔ Netherlands        | ~150 ms        | 150,000,000    | Speed-of-light bound      |

The exact figures change with hardware. Remember the **order of magnitude**, not the digits.

## Units

- 1 ns = 10⁻⁹ s
- 1 µs = 10⁻⁶ s = 1,000 ns
- 1 ms = 10⁻³ s = 1,000 µs = 1,000,000 ns

## Scaled to human time (1 ns → 1 second)

| Operation              | Real    | If 1 ns were 1 s |
| ---------------------- | ------- | ---------------- |
| L1 cache               | 1 ns    | 1 second         |
| RAM                    | 100 ns  | ~2 minutes       |
| SSD random read        | 50 µs   | ~14 hours        |
| Datacenter round trip  | 500 µs  | ~6 days          |
| HDD seek               | 10 ms   | ~4 months        |
| Cross-ocean round trip | 150 ms  | ~5 years         |

## Takeaways

1. **Memory is fast, disk is slow.** RAM is about 1000x faster than an SSD random read and about 100,000x faster than an HDD seek.
2. **Avoid disk seeks.** Sequential reads beat random reads by a wide margin, on HDDs most of all. This is why log-structured storage (LSM trees, Kafka) appends.
3. **Compress before sending over the network.** Compression costs microseconds, sending bytes across regions costs milliseconds.
4. **Datacenter round trips are cheap next to cross-region ones.** Put data near users with CDNs, edge caches and regional replicas.
5. **Cache-friendly layouts matter in C++.** `std::vector` (contiguous) beats `std::list` (pointer chasing) because each cache miss costs ~100 ns.
6. **Batch network calls.** 100 sequential calls inside the datacenter cost ~50 ms. One batched call costs ~0.5 ms.
7. **Locks and branch mispredicts are cheap but not free.** In a tight loop running millions of times, 20 ns per iteration adds up.

## Quick sanity checks I can do in an interview

- Reading 1 GB from RAM sequentially: ~1 GB / (~10 GB/s) ≈ **0.1 s**
- Reading 1 GB from an SSD sequentially: ~1 GB / (~1–3 GB/s) ≈ **0.3–1 s**
- Reading 1 GB from an HDD sequentially: ~1 GB / (~100–200 MB/s) ≈ **5–10 s**
- Sending 1 GB across a 1 Gbps link: 8 Gb / 1 Gbps ≈ **8 s**

**What confused me, and what cleared it up:**

**Source:** Jeff Dean's "Numbers Everyone Should Know", Peter Norvig's "Teach Yourself Programming in Ten Years", Colin Scott's interactive version (colin-scott.github.io/personal_website/research/interactive_latency.html), and *System Design Interview* Vol. 1 Ch. 2 (Alex Xu).
