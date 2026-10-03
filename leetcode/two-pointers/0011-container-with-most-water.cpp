// 11. Container With Most Water (Medium)
// https://leetcode.com/problems/container-with-most-water/
// Date:       2026-10-03
// Result:     alone | hint | read solution
// Time taken: __ min
//
// Approach, in two lines of my own words:
//
//
// Complexity: time O(?), space O(?)
// C++ I learned:

#include <assert.h>

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
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        while (left < right) {
            int area = 0;
            int leftHeight = height[left];
            int rightHeight = height[right];
            area = std::min(leftHeight, rightHeight) * (right - left);
            maxArea = std::max(area, maxArea);
            if (leftHeight < rightHeight) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};

int main() {
    [[maybe_unused]] Solution s;

       // LeetCode example 1: best pair is heights 8 and 7, width 7 -> 7 * 7
    std::vector<int> a{1, 8, 6, 2, 5, 4, 8, 3, 7};
    assert(s.maxArea(a) == 49);

    // LeetCode example 2: two lines only
    std::vector<int> b{1, 1};
    assert(s.maxArea(b) == 1);

    std::cout << "Container With Most Water: all tests passed\n";
}
