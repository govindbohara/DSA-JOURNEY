// 560. Subarray Sum Equals K (Medium)
// https://leetcode.com/problems/subarray-sum-equals-k/
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
    int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> map{{0, 1}};
        int out = 0;
        int sum = 0;
        for (int n : nums) {
            sum += n;
            out += map[sum - k];
            map[sum]++;
        }

        return out;
    }
};

int main() {
    Solution s;

    // LeetCode example 1: overlapping subarrays [1,1] and [1,1]
    std::vector<int> a{1, 1, 1};
    assert(s.subarraySum(a, 2) == 2);

    // LeetCode example 2: [1,2] and [3]
    std::vector<int> b{1, 2, 3};
    assert(s.subarraySum(b, 3) == 2);

    // Single element equal to k
    std::vector<int> c{5};
    assert(s.subarraySum(c, 5) == 1);

    // Single element, no match
    std::vector<int> d{5};
    assert(s.subarraySum(d, 3) == 0);

    // Negatives and zero: [1,-1], [1,-1,0], [0] (a sliding window breaks here)
    std::vector<int> e{1, -1, 0};
    assert(s.subarraySum(e, 0) == 3);

    // All zeros with k = 0: every subarray counts, n*(n+1)/2
    std::vector<int> f{0, 0, 0};
    assert(s.subarraySum(f, 0) == 6);

    // Negative k
    std::vector<int> g{-1, -1, 1};
    assert(s.subarraySum(g, -1) == 3);

    // Whole array is the only match
    std::vector<int> h{1, 2, 3, 4};
    assert(s.subarraySum(h, 10) == 1);

    // Mixed signs: [3,4], [7], [7,2,-3,1], [1,4,2]
    std::vector<int> i{3, 4, 7, 2, -3, 1, 4, 2};
    assert(s.subarraySum(i, 7) == 4);

    std::cout << "Subarray Sum Equals K: all tests passed\n";
}
