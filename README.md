# cpp-dsa-journey

Daily C++ practice on the way to low-latency software engineering: LeetCode patterns, learncpp.com exercises, notes and system design, all in C++20.

Every solution is its own small program with tests, built with CMake and checked by GitHub Actions on every push.

## Layout

| Folder                   | What goes in it                                             |
| ------------------------ | ----------------------------------------------------------- |
| `LOG.md`                 | One line per day, newest first                              |
| `leetcode/<pattern>/`    | One `.cpp` per problem, named `0217-contains-duplicate.cpp` |
| `learncpp/`              | Chapter exercises, named `ch04-exercises.cpp`               |
| `notes/`                 | Concepts explained in my own words                          |
| `system-design/`         | Written practice designs                                    |
| `include/lc.hpp`         | `ListNode`, `TreeNode` and helpers for building test inputs |
| `templates/`, `scripts/` | The problem template and helper scripts                     |

## Progress

| Month    | Patterns                                   | Solved |
| -------- | ------------------------------------------ | ------ |
| Oct 2026 | arrays-hashing, two-pointers, stack        | 0 / 19 |
| Nov 2026 | sliding-window, binary-search, linked-list | 0 / 21 |
| Dec 2026 | trees, tries, heap                         | 0 / 20 |
| Jan 2027 | backtracking, graphs, bit-manipulation     | 0 / 20 |
| Feb 2027 | dp-1d, intervals, greedy                   | 0 / 19 |
| Mar 2027 | advanced-graphs, dp-2d, math-geometry      | 0 / 13 |

## Build and run

Needs a C++20 compiler (GCC 13+ or Clang 17+) and CMake 3.20+. On Windows, use WSL2 with Ubuntu.

```bash
cmake -B build                                   # once
./scripts/run.sh leetcode/arrays-hashing/0217-contains-duplicate.cpp   # build and run one
cmake --build build -j && ctest --test-dir build --output-on-failure   # build and test everything
```

Debug builds run with AddressSanitizer and UndefinedBehaviorSanitizer, so memory bugs fail loudly.

## Adding a problem

```bash
./scripts/new.sh arrays-hashing 242 "Valid Anagram" Easy
```

Creates `leetcode/arrays-hashing/0242-valid-anagram.cpp` from the template. Paste LeetCode's function signature into `Solution`, add its examples as `assert`s, solve, then submit only the `Solution` class to LeetCode.

## Rules

1. Every line is C++.
2. I type the code myself.
3. Past 1.5x the target time, read the solution, then solve it again days later.
4. Log every day in `LOG.md`, including short days.

# DSA-JOURNEY

Changed for cpprun command shortcut

clang++ -std=c++17 -Wall -Wextra -pedantic-errors -g -ggdb -o "$out" "$file" && "./$out"
