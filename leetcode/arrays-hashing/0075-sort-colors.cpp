// 75. Sort Colors (Medium)
// https://leetcode.com/problems/sort-colors/
// Date:       2026-09-29
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
    void sortColors(std::vector<int>& nums) {
        int mid{0};
        int low{0};
        int high{static_cast<int>(nums.size()) - 1};

        while (mid <= high) {
            if (nums[mid] == 1) {
                mid++;
            } else if (nums[mid] == 2) {
                int temp = nums[high];
                nums[high] = nums[mid];
                nums[mid] = temp;
                high--;
            } else {
                int temp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = temp;
                low++;
                mid++;
            }
        }
    }
};

int main() {
    Solution s;

    // LeetCode example 1
    std::vector<int> a{2, 0, 2, 1, 1, 0};
    s.sortColors(a);
    assert(a == (std::vector<int>{0, 0, 1, 1, 2, 2}));

    // LeetCode example 2
    std::vector<int> b{2, 0, 1};
    s.sortColors(b);
    assert(b == (std::vector<int>{0, 1, 2}));

    // Single element
    std::vector<int> c{1};
    s.sortColors(c);
    assert(c == (std::vector<int>{1}));

    // All the same colour
    std::vector<int> d{2, 2, 2};
    s.sortColors(d);
    assert(d == (std::vector<int>{2, 2, 2}));

    // Two elements, reversed
    std::vector<int> e{1, 0};
    s.sortColors(e);
    assert(e == (std::vector<int>{0, 1}));

    // Fully reversed order
    std::vector<int> f{2, 2, 1, 1, 0, 0};
    s.sortColors(f);
    assert(f == (std::vector<int>{0, 0, 1, 1, 2, 2}));

    // No 1s at all
    std::vector<int> g{2, 0, 2, 0};
    s.sortColors(g);
    assert(g == (std::vector<int>{0, 0, 2, 2}));

    std::cout << "Sort Colors: all tests passed\n";
}
