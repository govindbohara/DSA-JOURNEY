// 523. Continuous Subarray Sum (Medium)
// https://leetcode.com/problems/continuous-subarray-sum/
// Date:       2026-10-09
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
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        int sum = 0;
        std::unordered_map<int, int> remainderMap{{0, -1}};

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int remainder = sum % k;
            if (remainderMap.contains(remainder)) {
                if (i - remainderMap[remainder] >= 2) return true;
            } else {
                remainderMap[remainder] = i;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    std::vector<int> a;

    // LeetCode example 1: [2, 4] sums to 6
    a = {23, 2, 4, 6, 7};
    assert(s.checkSubarraySum(a, 6) == true);

    // LeetCode example 2: the whole array sums to 42 = 7 * 6
    a = {23, 2, 6, 4, 7};
    assert(s.checkSubarraySum(a, 6) == true);

    // LeetCode example 3: no subarray sums to a multiple of 13
    a = {23, 2, 6, 4, 7};
    assert(s.checkSubarraySum(a, 13) == false);

    // Single element: too short, even though 0 is a multiple of k
    a = {0};
    assert(s.checkSubarraySum(a, 1) == false);

    // Single element that is a multiple of k: still too short
    a = {6};
    assert(s.checkSubarraySum(a, 6) == false);

    // Two zeros: sum 0 counts as a multiple of k
    a = {0, 0};
    assert(s.checkSubarraySum(a, 1) == true);

    // Zeros later in the array
    a = {5, 0, 0, 0};
    assert(s.checkSubarraySum(a, 3) == true);

    // Same remainder at neighbouring prefixes, but the subarray is length 1
    a = {1, 0};
    assert(s.checkSubarraySum(a, 2) == false);

    // 12 alone is a multiple of 6, but no subarray of length >= 2 is
    a = {1, 2, 12};
    assert(s.checkSubarraySum(a, 6) == false);

    // The answer starts at index 0: needs the "remainder 0 at index -1" case
    a = {2, 4, 3};
    assert(s.checkSubarraySum(a, 6) == true);

    // k = 1: any pair works
    a = {1, 1};
    assert(s.checkSubarraySum(a, 1) == true);

    // k larger than every sum
    a = {1, 2, 3};
    assert(s.checkSubarraySum(a, 100) == false);

    std::cout << "Continuous Subarray Sum: all tests passed\n";
}
