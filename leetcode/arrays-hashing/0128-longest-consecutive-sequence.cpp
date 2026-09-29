// 128. Longest Consecutive Sequence (Medium)
// https://leetcode.com/problems/longest-consecutive-sequence/
// Date:       2026-09-29
// Result:     alone | hint | read solution
// Time taken: __ min
//
// Approach, in two lines of my own words:
//
//
// Complexity: time O(?), space O(?)
// C++ I learned:

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "lc.hpp"

class Solution {
   public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        int max = 0;
        for (int& n : nums) {
            seen.insert(n);
        }
        for (int n : seen) {
            if (seen.find(n - 1) != seen.end()) continue;
            int len = 1;
            while (seen.find(n + len) != seen.end()) {
                len++;
            }
            max = std::max(len, max);
        }

        return max;
    }
};

int main() {
    Solution s;

    // LeetCode examples
    std::vector<int> a{100, 4, 200, 1, 3, 2};
    assert(s.longestConsecutive(a) == 4);

    std::vector<int> b{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    assert(s.longestConsecutive(b) == 9);

    // Duplicates don't extend the run
    std::vector<int> c{1, 0, 1, 2};
    assert(s.longestConsecutive(c) == 3);

    // Empty input
    std::vector<int> d{};
    assert(s.longestConsecutive(d) == 0);

    // Single element
    std::vector<int> e{5};
    assert(s.longestConsecutive(e) == 1);

    // Run crosses zero
    std::vector<int> f{-2, -1, 0, 1};
    assert(s.longestConsecutive(f) == 4);

    // No two numbers are consecutive
    std::vector<int> g{1, 3, 5, 7};
    assert(s.longestConsecutive(g) == 1);

    // Several runs of the same length
    std::vector<int> h{9, 1, -3, 2, 4, 8, 3, -1, 6, -2, -4, 7};
    assert(s.longestConsecutive(h) == 4);

    std::cout << "Longest Consecutive Sequence: all tests passed\n";
}
