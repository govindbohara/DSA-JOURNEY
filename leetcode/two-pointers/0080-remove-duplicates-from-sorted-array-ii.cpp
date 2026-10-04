// 80. Remove Duplicates from Sorted Array II (Medium)
// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Date:       2026-10-05
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
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }
        int left = 2;
        for (int right = 2; right < nums.size(); right++) {
            if (nums[right] != nums[left - 2]) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};

// LeetCode's judge: k must match, and the first k elements must match.
// Whatever is left after index k does not matter.
static bool check(std::vector<int> nums, const std::vector<int>& expected) {
    Solution s;
    int k = s.removeDuplicates(nums);
    if (k != static_cast<int>(expected.size())) return false;
    return std::equal(expected.begin(), expected.end(), nums.begin());
}

int main() {
    // LeetCode example 1: the third 1 is dropped
    assert(check({1, 1, 1, 2, 2, 3}, {1, 1, 2, 2, 3}));

    // LeetCode example 2: runs of 0s and 1s get cut down to two each
    assert(check({0, 0, 1, 1, 1, 1, 2, 3, 3}, {0, 0, 1, 1, 2, 3, 3}));

    // Single element
    assert(check({5}, {5}));

    // Two equal elements: both are allowed to stay
    assert(check({7, 7}, {7, 7}));

    // No duplicates at all: nothing changes
    assert(check({1, 2, 3, 4}, {1, 2, 3, 4}));

    // All the same value: only two survive
    assert(check({2, 2, 2, 2, 2}, {2, 2}));

    // Long run in the middle, then values that must shift left over the gap
    assert(check({1, 2, 2, 2, 2, 3, 3, 3, 4}, {1, 2, 2, 3, 3, 4}));

    // Negatives and constraint extremes (-10^4 .. 10^4)
    assert(
        check({-10000, -10000, -10000, 0, 10000, 10000, 10000}, {-10000, -10000, 0, 10000, 10000}));

    std::cout << "Remove Duplicates from Sorted Array II: all tests passed\n";
}
