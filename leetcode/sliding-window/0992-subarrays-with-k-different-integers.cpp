// 992. Subarrays with K Different Integers (Hard)
// https://leetcode.com/problems/subarrays-with-k-different-integers/
// Date:       2026-10-16
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
    int subarraysWithKDistinct(std::vector<int>& nums, int k) {
        // exactly k = at most k - at most (k - 1)
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

   private:
    int atMostK(std::vector<int>& nums, int k) {
        if (k < 0) return 0;

        int left = 0;
        int count = 0;
        int distinct = 0;
        int n = nums.size();

        // values are in [1, n]
        std::vector<int> freq(n + 1, 0);

        for (int r = 0; r < n; r++) {
            if (freq[nums[r]]++ == 0) {
                distinct++;
            }

            while (distinct > k) {
                if (--freq[nums[left++]] == 0) {
                    distinct--;
                }
            }

            // every subarray ending at r and starting in [left, r]
            count += r - left + 1;
        }

        return count;
    }
};

int main() {
    Solution s;

    // LeetCode example 1
    std::vector<int> n1 = {1, 2, 1, 2, 3};
    assert(s.subarraysWithKDistinct(n1, 2) == 7);

    // LeetCode example 2
    std::vector<int> n2 = {1, 2, 1, 3, 4};
    assert(s.subarraysWithKDistinct(n2, 3) == 3);

    // Single element, k = 1
    std::vector<int> n3 = {1};
    assert(s.subarraysWithKDistinct(n3, 1) == 1);

    // All same, k = 1: every subarray counts (4 * 5 / 2)
    std::vector<int> n4 = {2, 2, 2, 2};
    assert(s.subarraysWithKDistinct(n4, 1) == 10);

    // k larger than the number of distinct values
    std::vector<int> n5 = {1, 2, 1};
    assert(s.subarraysWithKDistinct(n5, 3) == 0);

    std::cout << "Subarrays with K Different Integers: all tests passed\n";
}
