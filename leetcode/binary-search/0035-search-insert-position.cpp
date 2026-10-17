// 35. Search Insert Position (Easy)
// https://leetcode.com/problems/search-insert-position/
// Date:       2026-10-17
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
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main() {
    Solution s;

    // LeetCode example 1: target found
    std::vector<int> n1 = {1, 3, 5, 6};
    assert(s.searchInsert(n1, 5) == 2);

    // LeetCode example 2: insert in the middle
    assert(s.searchInsert(n1, 2) == 1);

    // LeetCode example 3: insert at the end
    assert(s.searchInsert(n1, 7) == 4);

    // Insert at the start
    assert(s.searchInsert(n1, 0) == 0);

    // Single element
    std::vector<int> n2 = {1};
    assert(s.searchInsert(n2, 1) == 0);
    assert(s.searchInsert(n2, 2) == 1);

    std::cout << "Search Insert Position: all tests passed\n";
}
