// 167. Two Sum II - Input Array Is Sorted (Medium)
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
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
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1};
            } else if (sum > target) {
                right--;

            } else {
                left++;
            }
        }
        return {-1, -1};
    }
};

int main() {
    Solution s;

    // LeetCode example 1
    std::vector<int> a{2, 7, 11, 15};
    assert(s.twoSum(a, 9) == (std::vector<int>{1, 2}));

    // LeetCode example 2: answer uses the first and last elements
    std::vector<int> b{2, 3, 4};
    assert(s.twoSum(b, 6) == (std::vector<int>{1, 3}));

    // LeetCode example 3: negative numbers
    std::vector<int> c{-1, 0};
    assert(s.twoSum(c, -1) == (std::vector<int>{1, 2}));

    // Duplicate values that form the answer
    std::vector<int> d{1, 2, 3, 4, 4, 9, 56, 90};
    assert(s.twoSum(d, 8) == (std::vector<int>{4, 5}));

    // Mix of negatives and positives, answer in the middle
    std::vector<int> e{-3, -1, 0, 2, 5};
    assert(s.twoSum(e, 4) == (std::vector<int>{2, 5}));

    std::cout << "Two Sum II - Input Array Is Sorted: all tests passed\n";
}
