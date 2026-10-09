// 18. 4Sum (Medium)
// https://leetcode.com/problems/4sum/
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
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        if (nums.size() < 4) return result;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1]) left++;

                        while (left < right && nums[right] == nums[right + 1]) right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return result;
    }
};

// LeetCode accepts quadruplets in any order, so normalise before comparing.
std::vector<std::vector<int>> normalised(std::vector<std::vector<int>> v) {
    for (auto& q : v) std::sort(q.begin(), q.end());
    std::sort(v.begin(), v.end());
    return v;
}

using Quads = std::vector<std::vector<int>>;

int main() {
    Solution s;

    // LeetCode example 1: three different quadruplets
    std::vector<int> a{1, 0, -1, 0, -2, 2};
    assert(normalised(s.fourSum(a, 0)) == (Quads{{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}}));

    // LeetCode example 2: all the same number, still only one quadruplet
    std::vector<int> b{2, 2, 2, 2, 2};
    assert(normalised(s.fourSum(b, 8)) == (Quads{{2, 2, 2, 2}}));

    // Fewer than four numbers
    std::vector<int> c{1, 2, 3};
    assert(normalised(s.fourSum(c, 6)).empty());

    // Exactly four numbers that work
    std::vector<int> d{1, 2, 3, 4};
    assert(normalised(s.fourSum(d, 10)) == (Quads{{1, 2, 3, 4}}));

    // No quadruplet reaches the target
    std::vector<int> e{1, 2, 3, 4, 5};
    assert(normalised(s.fourSum(e, 100)).empty());

    // Negative target
    std::vector<int> f{-3, -2, -1, 0, 0, 1, 2, 3};
    assert(normalised(s.fourSum(f, -5)) == (Quads{{-3, -2, -1, 1}, {-3, -2, 0, 0}}));

    // Overflow trap: four * 10^9 wraps around to -294967296 in int
    std::vector<int> g{1000000000, 1000000000, 1000000000, 1000000000};
    assert(normalised(s.fourSum(g, -294967296)).empty());

    // Big values that really do sum to the target
    std::vector<int> h{0, 0, 0, 1000000000, 1000000000, 1000000000, 1000000000};
    assert(normalised(s.fourSum(h, 1000000000)) == (Quads{{0, 0, 0, 1000000000}}));

    // Heavy duplicates: skip repeats at every level
    std::vector<int> i{-2, -2, -1, -1, 0, 0, 1, 1, 2, 2};
    assert(normalised(s.fourSum(i, 0)) == (Quads{{-2, -2, 2, 2},
                                                 {-2, -1, 1, 2},
                                                 {-2, 0, 0, 2},
                                                 {-2, 0, 1, 1},
                                                 {-1, -1, 0, 2},
                                                 {-1, -1, 1, 1},
                                                 {-1, 0, 0, 1}}));

    std::cout << "4Sum: all tests passed\n";
}
