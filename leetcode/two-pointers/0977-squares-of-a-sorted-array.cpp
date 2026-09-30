// 977. Squares of a Sorted Array (Easy)
// https://leetcode.com/problems/squares-of-a-sorted-array/
// Date:       2026-09-30
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
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        std::vector<int> out(nums.size());

        for (int i = nums.size() - 1; i >= 0; i--) {
            int leftValue = std::abs(nums[left]);
            int rightValue = std::abs(nums[right]);

            if (leftValue > rightValue) {
                out[i] = leftValue * leftValue;
                left++;

            } else {
                out[i] = rightValue * rightValue;
                right--;
            }
        }
        return out;
    }
};

int main() {
    Solution s;

    // LeetCode example 1: negatives and positives
    std::vector<int> a{-4, -1, 0, 3, 10};
    assert(s.sortedSquares(a) == (std::vector<int>{0, 1, 9, 16, 100}));

    // LeetCode example 2: largest square comes from a negative
    std::vector<int> b{-7, -3, 2, 3, 11};
    assert(s.sortedSquares(b) == (std::vector<int>{4, 9, 9, 49, 121}));

    // Single element
    std::vector<int> c{-5};
    assert(s.sortedSquares(c) == (std::vector<int>{25}));

    // All negative: result is the input reversed, then squared
    std::vector<int> d{-5, -3, -2, -1};
    assert(s.sortedSquares(d) == (std::vector<int>{1, 4, 9, 25}));

    // All non-negative: order does not change
    std::vector<int> e{0, 1, 2, 6};
    assert(s.sortedSquares(e) == (std::vector<int>{0, 1, 4, 36}));

    // Same absolute value on both sides
    std::vector<int> f{-2, -2, 0, 2, 2};
    assert(s.sortedSquares(f) == (std::vector<int>{0, 4, 4, 4, 4}));

    // Constraint extremes: 10^4 squared still fits in an int
    std::vector<int> g{-10000, 10000};
    assert(s.sortedSquares(g) == (std::vector<int>{100000000, 100000000}));

    std::cout << "Squares of a Sorted Array: all tests passed\n";
}
