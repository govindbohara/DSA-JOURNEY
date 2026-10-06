# learncpp chapter 8 — Control flow (from break/continue onwards)

Loops themselves were familiar from C. These are the parts that were new, or that
C taught me differently.

---

## break vs continue

`break` leaves the loop entirely. `continue` jumps to the **next iteration**, which
in a `for` loop means the update expression still runs, but in a `while` loop it
does not.

```cpp
// Fine: the for-loop's ++i still runs when continue fires.
for (int i = 0; i < 10; ++i) {
    if (i % 2 == 0) continue;
    std::cout << i << ' ';          // 1 3 5 7 9
}

// Hangs forever: continue skips the ++i.
int i = 0;
while (i < 10) {
    if (i % 2 == 0) continue;       // BUG: i never changes
    std::cout << i << ' ';
    ++i;
}
```

The fix is to increment before the `continue`, or use a `for` loop so the update
can't be skipped.

`break` only exits **one** level. Getting out of nested loops needs a flag, a
function with `return`, or `goto`:

```cpp
// The one case where goto is still the clearest option.
for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
        if (grid[r][c] == target) goto found;
    }
}
std::cout << "not found\n";
found:
```

Better in practice: put the search in its own function and `return` from it.

---

## goto

Jumps to a label **within the same function**. Two rules worth knowing:

- It cannot jump *forward* over a variable's initialisation (the compiler rejects it).
- It can jump *backward* past an initialisation, which re-runs that initialisation.

```cpp
int tries = 0;
retry:
    ++tries;
    if (!connect() && tries < 3) goto retry;
```

C used `goto cleanup;` for error handling because there were no destructors. C++
has RAII, so the destructor does the cleanup when the scope exits. That's the
whole reason `goto` is almost dead in C++ and still common in C.

---

## Halts

| Call | Local destructors | Static destructors | Use |
|---|---|---|---|
| `return` from `main` | yes | yes | normal exit |
| `std::exit(code)` | **no** | yes | emergency exit, single-threaded |
| `std::abort()` | no | no | unrecoverable; raises SIGABRT, can dump core |
| `std::quick_exit(code)` | no | no | exit without cleanup, pairs with `at_quick_exit` |

```cpp
#include <cstdlib>

void writeLog();                   // registered cleanup

int main() {
    std::atexit(writeLog);         // runs on exit() and on normal return
    // ...
    if (fatal) std::exit(1);       // local destructors DO NOT run: anything
                                   // holding a file handle or buffer leaks
}
```

The practical rule: return normally and let destructors run. `std::exit` in a
multi-threaded program is particularly dangerous, because other threads keep
running while statics are being destroyed.

---

## Random numbers

This is the part C did badly and C++ does properly. `rand()` is low quality and
`rand() % n` is biased.

### Why `% n` is biased

`rand()` returns 0..RAND_MAX. If the range doesn't divide evenly, the low values
appear more often. With RAND_MAX = 32767 and `% 3`, the value 0 comes up 10923
times per cycle and 2 comes up 10922. Small here, large when the range is big.

### The modern setup

```cpp
#include <chrono>
#include <random>

// One engine for the whole program, seeded once, not per call.
std::mt19937 makeEngine() {
    std::random_device rd;
    std::seed_seq seq{
        static_cast<std::seed_seq::result_type>(
            std::chrono::steady_clock::now().time_since_epoch().count()),
        rd(), rd(), rd(), rd(), rd(), rd(), rd()
    };
    return std::mt19937{ seq };
}

std::mt19937& rng() {
    static std::mt19937 engine{ makeEngine() };   // created once, on first use
    return engine;
}

int roll(int lo, int hi) {
    std::uniform_int_distribution<int> dist{ lo, hi };   // inclusive both ends
    return dist(rng());
}
```

Points to remember:

- **The engine produces bits; the distribution shapes them.** Never do the shaping
  yourself with `%`.
- **Seed once.** Creating a new engine per call, seeded from a clock, gives
  repeated values because the clock barely moved.
- **`std::random_device` can be fake.** On some older MinGW builds it returns the
  same sequence every run, which is why the seed mixes in the clock too.
- **A fixed seed is a feature** in tests: `std::mt19937 engine{ 42 };` gives the
  same sequence every run, so a failing test is reproducible.
- `std::mt19937` is 32-bit, `std::mt19937_64` is 64-bit. Both hold ~2.5 KB of
  state, which is why you don't want one per call.

```cpp
// Generating test data for the order book later:
std::uniform_int_distribution<int> priceDist{ 9900, 10100 };
std::uniform_int_distribution<int> qtyDist{ 1, 500 };
```

---

## What I got wrong / had to look up

-
-

## Where this matters later

- `std::mt19937` with a fixed seed is how I'll generate reproducible message
  streams for benchmarking the order book.
- `std::exit` skipping local destructors is the same RAII idea that Project 1
  (`unique_ptr`, `vector`) is built on.
- Branch-heavy loops matter for the CPU's branch predictor, which is a chapter 2
  topic in the systems reading later.
