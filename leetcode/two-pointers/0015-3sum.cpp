// 15. 3Sum (Medium)
// https://leetcode.com/problems/3sum/
// Date:       2026-10-01
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
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> output;
        for (int i = 0; i < nums.size(); i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    output.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else if (sum > 0) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return output;
    }
};

// LeetCode accepts triplets in any order, so normalise before comparing.
std::vector<std::vector<int>> normalised(std::vector<std::vector<int>> v) {
    for (auto& t : v) std::sort(t.begin(), t.end());
    std::sort(v.begin(), v.end());
    return v;
}

using Triplets = std::vector<std::vector<int>>;

int main() {
    Solution s;

    // LeetCode example 1: duplicates in input, no duplicate triplets in output
    std::vector<int> a{-1, 0, 1, 2, -1, -4};
    assert(normalised(s.threeSum(a)) == (Triplets{{-1, -1, 2}, {-1, 0, 1}}));

    // LeetCode example 2: no triplet sums to zero
    std::vector<int> b{0, 1, 1};
    assert(normalised(s.threeSum(b)).empty());

    // LeetCode example 3: all zeros
    std::vector<int> c{0, 0, 0};
    assert(normalised(s.threeSum(c)) == (Triplets{{0, 0, 0}}));

    // Many zeros: still only one triplet
    std::vector<int> d{0, 0, 0, 0, 0};
    assert(normalised(s.threeSum(d)) == (Triplets{{0, 0, 0}}));

    // All positive: impossible
    std::vector<int> e{1, 2, 3, 4};
    assert(normalised(s.threeSum(e)).empty());

    // Heavy duplicates on both sides
    std::vector<int> f{-2, -2, 0, 0, 2, 2};
    assert(normalised(s.threeSum(f)) == (Triplets{{-2, 0, 2}}));

    // Several distinct answers
    std::vector<int> g{-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
    assert(normalised(s.threeSum(g)) ==
           (Triplets{{-4, -2, 6}, {-4, 0, 4}, {-4, 1, 3}, {-4, 2, 2}, {-2, -2, 4}, {-2, 0, 2}}));

    std::cout << "3Sum: all tests passed\n";
}
