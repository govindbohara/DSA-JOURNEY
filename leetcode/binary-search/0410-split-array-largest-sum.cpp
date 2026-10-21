// 410. Split Array Largest Sum (Hard)
// https://leetcode.com/problems/split-array-largest-sum/
// Date:       2026-10-21
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
    bool check(int mid, std::vector<int>& nums, int k) {
        int sum = 0;
        int count = 1;

        for (int n : nums) {
            if (sum + n > mid) {
                count++;
                sum = n;
            } else {
                sum += n;
            }
        }
        return count <= k;
    }
    int splitArray(std::vector<int>& nums, int k) {
        int left = nums[0];
        int right = 0;

        for (int n : nums) {
            if (n > left) {
                left = n;
            }
            right += n;
        }
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (check(mid, nums, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main() {
    Solution s;

    // LeetCode example 1
    std::vector<int> a1 = {7, 2, 5, 10, 8};
    assert(s.splitArray(a1, 2) == 18);

    // LeetCode example 2
    std::vector<int> a2 = {1, 2, 3, 4, 5};
    assert(s.splitArray(a2, 2) == 9);

    // k = 1: whole array is one subarray
    std::vector<int> a3 = {1, 2, 3};
    assert(s.splitArray(a3, 1) == 6);

    // k = n: answer is the max element
    std::vector<int> a4 = {4, 1, 9, 2};
    assert(s.splitArray(a4, 4) == 9);

    // Single element
    std::vector<int> a5 = {5};
    assert(s.splitArray(a5, 1) == 5);

    std::cout << "Split Array Largest Sum: all tests passed\n";
}
