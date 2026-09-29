// 169. Majority Element (Easy)
// https://leetcode.com/problems/majority-element/
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
    int majorityElement(std::vector<int>& nums) {
        int curr = 0, count = 0;
        for (int n : nums) {
            if (count == 0) {
                curr = n;
            }
            if (curr == n) {
                count++;
            } else {
                count--;
            }
        }
        return curr;
    }
};

int main() {
    Solution s;

    // LeetCode examples
    std::vector<int> a{3, 2, 3};
    assert(s.majorityElement(a) == 3);

    std::vector<int> b{2, 2, 1, 1, 1, 2, 2};
    assert(s.majorityElement(b) == 2);

    // Single element
    std::vector<int> c{1};
    assert(s.majorityElement(c) == 1);

    // Negative majority
    std::vector<int> d{-1, -1, -1, 5};
    assert(s.majorityElement(d) == -1);

    // Majority not at the start
    std::vector<int> e{6, 5, 5};
    assert(s.majorityElement(e) == 5);

    // Majority only at the end
    std::vector<int> f{1, 2, 3, 4, 4, 4, 4};
    assert(s.majorityElement(f) == 4);

    std::cout << "Majority Element: all tests passed\n";
}
