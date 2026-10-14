// 1004. Max Consecutive Ones III (Medium)
// https://leetcode.com/problems/max-consecutive-ones-iii/
// Date:       2026-10-14
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
    int longestOnes(std::vector<int>& nums, int k) {
        int left = 0;
        int maxV = 0;
        int z = 0;
        int n = nums.size();

        for (int right = 0; right < n; right++) {
            int v = nums[right];
            if (v == 0) {
                z++;
            }
            while (z > k) {
                if (nums[left] == 0) z--;
                left++;
            }
            maxV = std::max(maxV, right - left + 1);
        }

        return maxV;
    }
};

int main() {
    Solution s;

    // LeetCode example 1: flip the two zeros before the last run of ones
    std::vector<int> n1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    assert(s.longestOnes(n1, 2) == 6);

    // LeetCode example 2
    std::vector<int> n2 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    assert(s.longestOnes(n2, 3) == 10);

    // k = 0: longest run of ones as it is
    std::vector<int> n3 = {1, 1, 0, 1, 1, 1};
    assert(s.longestOnes(n3, 0) == 3);

    // All zeros, k = 0: nothing to keep
    std::vector<int> n4 = {0, 0, 0};
    assert(s.longestOnes(n4, 0) == 0);

    // k covers every zero: whole array
    std::vector<int> n5 = {0, 1, 0, 1};
    assert(s.longestOnes(n5, 2) == 4);

    std::cout << "Max Consecutive Ones III: all tests passed\n";
}
