// 209. Minimum Size Subarray Sum (Medium)
// https://leetcode.com/problems/minimum-size-subarray-sum/
// Date:       2026-10-13
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
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "lc.hpp"

class Solution {
   public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int left = 0;
        int minLen = INT_MAX;
        int sum = 0;
        int n = nums.size();
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum >= target) {
                minLen = std::min(minLen, right - left + 1);
                sum = sum - nums[left];
                left++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};

int main() {
    Solution s;

    // LeetCode example 1: [4, 3] is the shortest
    std::vector<int> n1 = {2, 3, 1, 2, 4, 3};
    assert(s.minSubArrayLen(7, n1) == 2);

    // LeetCode example 2: one element is enough
    std::vector<int> n2 = {1, 4, 4};
    assert(s.minSubArrayLen(4, n2) == 1);

    // LeetCode example 3: whole array is too small
    std::vector<int> n3 = {1, 1, 1, 1, 1, 1, 1, 1};
    assert(s.minSubArrayLen(11, n3) == 0);

    // Needs the whole array exactly
    std::vector<int> n4 = {1, 2, 3};
    assert(s.minSubArrayLen(6, n4) == 3);

    // Single element below target
    std::vector<int> n5 = {5};
    assert(s.minSubArrayLen(6, n5) == 0);

    // Best window is at the very end
    std::vector<int> n6 = {1, 1, 1, 10};
    assert(s.minSubArrayLen(10, n6) == 1);

    std::cout << "Minimum Size Subarray Sum: all tests passed\n";
}
