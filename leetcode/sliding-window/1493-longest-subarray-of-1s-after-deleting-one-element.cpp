// 1493. Longest Subarray of 1's After Deleting One Element (Medium)
// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
// Date:       2026-10-15
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
    int longestSubarray(std::vector<int>& nums) {
        int left = 0;
        int zeros = 0;
        int maxV = 0;
        int n = nums.size();

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) zeros++;
            while (zeros > 1) {
                if (nums[left] == 0) zeros--;
                left++;
            }
            // window holds at most one zero; one element must be deleted
            maxV = std::max(maxV, right - left);
        }
        return maxV;
    }
};

int main() {
    Solution s;

    // LeetCode example 1: delete the zero at index 2
    std::vector<int> n1 = {1, 1, 0, 1};
    assert(s.longestSubarray(n1) == 3);

    // LeetCode example 2: delete the zero at index 4
    std::vector<int> n2 = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    assert(s.longestSubarray(n2) == 5);

    // LeetCode example 3: all ones, must still delete one
    std::vector<int> n3 = {1, 1, 1};
    assert(s.longestSubarray(n3) == 2);

    // All zeros
    std::vector<int> n4 = {0, 0, 0};
    assert(s.longestSubarray(n4) == 0);

    // Single element
    std::vector<int> n5 = {1};
    assert(s.longestSubarray(n5) == 0);

    std::cout << "Longest Subarray of 1's After Deleting One Element: all tests passed\n";
}
