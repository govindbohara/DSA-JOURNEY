// 442. Find All Duplicates in an Array (Medium)
// https://leetcode.com/problems/find-all-duplicates-in-an-array/
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
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        std::vector<int> res;
        res.reserve(nums.size() / 2);
        for (int n : nums) {
            int i = abs(n) - 1;
            if (nums[i] < 0)
                res.push_back(i + 1);
            else
                nums[i] = -nums[i];
        }

        return res;
    }
};

// LeetCode accepts any order, so sort before comparing.
std::vector<int> sorted(std::vector<int> v) {
    std::sort(v.begin(), v.end());
    return v;
}

int main() {
    Solution s;

    // LeetCode example 1
    std::vector<int> a{4, 3, 2, 7, 8, 2, 3, 1};
    assert(sorted(s.findDuplicates(a)) == (std::vector<int>{2, 3}));

    // LeetCode example 2
    std::vector<int> b{1, 1, 2};
    assert(sorted(s.findDuplicates(b)) == (std::vector<int>{1}));

    // LeetCode example 3: single element
    std::vector<int> c{1};
    assert(s.findDuplicates(c).empty());

    // No duplicates: a permutation of 1..n
    std::vector<int> d{5, 4, 3, 2, 1};
    assert(s.findDuplicates(d).empty());

    // Every value appears twice
    std::vector<int> e{1, 1, 2, 2, 3, 3};
    assert(sorted(s.findDuplicates(e)) == (std::vector<int>{1, 2, 3}));

    // Duplicate is the largest allowed value (n)
    std::vector<int> f{2, 2};
    assert(sorted(s.findDuplicates(f)) == (std::vector<int>{2}));

    std::cout << "Find All Duplicates in an Array: all tests passed\n";
}
