// 41. First Missing Positive (Hard)
// https://leetcode.com/problems/first-missing-positive/
// Date:       2026-10-02
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
    int firstMissingPositive(std::vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            while (nums[i] <= 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
            }
            {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return nums.size() + 1;
        // Constraint: O(n) time, O(1) extra space.
    }
};

int main() {
    Solution s;

    // LeetCode example 1
    std::vector<int> a{1, 2, 0};
    assert(s.firstMissingPositive(a) == 3);

    // LeetCode example 2: gap in the middle
    std::vector<int> b{3, 4, -1, 1};
    assert(s.firstMissingPositive(b) == 2);

    // LeetCode example 3: 1 is missing
    std::vector<int> c{7, 8, 9, 11, 12};
    assert(s.firstMissingPositive(c) == 1);

    // Single element that is 1
    std::vector<int> d{1};
    assert(s.firstMissingPositive(d) == 2);

    // Already 1..n: answer is n + 1
    std::vector<int> e{4, 3, 2, 1};
    assert(s.firstMissingPositive(e) == 5);

    // Duplicates
    std::vector<int> f{1, 1, 2, 2};
    assert(s.firstMissingPositive(f) == 3);

    // All non-positive
    std::vector<int> g{0, -1, -2};
    assert(s.firstMissingPositive(g) == 1);

    std::cout << "First Missing Positive: all tests passed\n";
}
