# Back-of-the-Envelope Estimation

**In one sentence:** Quick rough math, using round numbers, that tells me whether a design can handle the expected load before I spend time on details.

**Why it matters:** It tells me how many servers I need, whether the data fits in memory, and whether one database can keep up. Being within 10x is good enough. The point is the reasoning, not the exact answer.

## Powers of two (data volume)

| Power | Exact value         | Approx.      | Name      | Short |
| ----- | ------------------- | ------------ | --------- | ----- |
| 2¹⁰   | 1,024               | 1 thousand   | Kilobyte  | 1 KB  |
| 2²⁰   | 1,048,576           | 1 million    | Megabyte  | 1 MB  |
| 2³⁰   | 1,073,741,824       | 1 billion    | Gigabyte  | 1 GB  |
| 2⁴⁰   | ~1.1 × 10¹²         | 1 trillion   | Terabyte  | 1 TB  |
| 2⁵⁰   | ~1.1 × 10¹⁵         | 1 quadrillion| Petabyte  | 1 PB  |

Common sizes:

- `char` / ASCII character: 1 byte
- Unicode (UTF-8) character: 1–4 bytes
- `int32`: 4 bytes, `int64` / `double` / pointer: 8 bytes
- UUID: 16 bytes
- Timestamp: 8 bytes
- A short text post: ~100s of bytes to 1 KB
- A compressed photo: ~200 KB – 2 MB
- A minute of compressed video: ~5–50 MB

## Time shortcuts

- 1 day = 86,400 s ≈ **10⁵ s** (round to 100,000)
- 1 month ≈ 2.5 × 10⁶ s
- 1 year ≈ 3 × 10⁷ s
- So **1 million requests/day ≈ 10 requests/sec (QPS)** (10⁶ / 10⁵)

## Availability numbers ("the nines")

| Availability | Downtime per year | Downtime per day |
| ------------ | ----------------- | ---------------- |
| 99%          | 3.65 days         | 14.4 min         |
| 99.9%        | 8.77 hours        | 1.44 min         |
| 99.99%       | 52.6 min          | 8.6 s            |
| 99.999%      | 5.26 min          | 864 ms           |
| 99.9999%     | 31.5 s            | 86 ms            |

Cloud providers usually promise 99.9% or better in their SLAs.

## The method

1. **Write down assumptions** (DAU, actions per user, object sizes, read:write ratio). Say them out loud.
2. **Round hard.** 99,987 / 9.1 → 100,000 / 10 = 10,000.
3. **Label units** on every number (KB vs MB, per second vs per day).
4. **Estimate:**
   - **QPS** = DAU × actions per user per day / 10⁵
   - **Peak QPS** ≈ 2–3 × average QPS
   - **Storage** = writes per day × object size × retention period
   - **Bandwidth** = QPS × object size
   - **Servers** = peak QPS / QPS one server handles (~1k–10k for a simple service)
   - **Cache** = follow the 80/20 rule: cache ~20% of daily read data
5. **Sanity check** against the latency numbers ([latency-numbers.md](latency-numbers.md)).

## Worked example: Twitter-like service

Assumptions:

- 300 million monthly active users, 50% use it daily → **150 M DAU**
- Each user posts **2 tweets/day**
- **10%** of tweets contain media
- Data kept for **5 years**
- Tweet size: `tweet_id` 64 B + text 140 B + metadata ~100 B ≈ **~300 B**
- Media size: **1 MB**

**Write QPS:**

- Tweets/day = 150 M × 2 = 300 M
- QPS = 300 M / 10⁵ ≈ **3,000 tweets/s**
- Peak ≈ 2 × 3,000 = **~6,000 tweets/s**

**Media storage per day:**

- 300 M × 10% × 1 MB = 30 M MB = **30 TB/day**

**Media storage for 5 years:**

- 30 TB × 365 × 5 ≈ 30 TB × 1,825 ≈ **~55 PB**

**Text storage per day:**

- 300 M × 300 B = 90 GB/day → 5 years ≈ **~165 TB** (small next to media)

**Read side** (assume read:write = 100:1):

- Read QPS ≈ 3,000 × 100 = **300,000 reads/s** → needs heavy caching and many read replicas.

## Worked example: URL shortener

- 100 M new URLs/day → write QPS ≈ 100 M / 10⁵ = **1,000/s**
- Read:write = 10:1 → read QPS ≈ **10,000/s**
- Each record ≈ 500 B; 10 years → 100 M × 365 × 10 × 500 B ≈ 365 B records × 500 B ≈ **~180 TB**
- Short-code length: 62 characters (a–z, A–Z, 0–9). 62⁶ ≈ 57 billion, 62⁷ ≈ 3.5 trillion → **7 characters** covers 365 billion URLs.

## Tips

- Interviewers care about the **process**, not the exact answer.
- Always state the **unit**. "5" means nothing, "5 MB" does.
- Round to powers of 10 to keep the arithmetic in your head.
- Typical things to estimate: **QPS, peak QPS, storage, cache size, bandwidth, number of servers.**
- Keep a few anchors: one commodity server handles roughly **thousands to tens of thousands of simple requests/s**, has **tens to hundreds of GB of RAM**, and a single relational DB node handles roughly **thousands of writes/s**.

**What confused me, and what cleared it up:**

**Source:** *System Design Interview* Vol. 1 Ch. 2 (Alex Xu), Jeff Dean's latency numbers, and the Google SRE book's availability tables.
