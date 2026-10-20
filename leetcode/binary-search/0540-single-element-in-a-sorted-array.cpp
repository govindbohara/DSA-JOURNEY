// 540. Single Element in a Sorted Array (Medium)
// https://leetcode.com/problems/single-element-in-a-sorted-array/
// Date:       2026-10-20
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
    int singleNonDuplicate(std::vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (mid % 2 == 1) mid--;

            if (nums[mid] != nums[mid + 1]) {
                high = mid;
            } else {
                low = mid + 2;
            }
        }

        return nums[low];
    }
};

int main() {
    Solution s;

    // LeetCode example 1
    std::vector<int> n1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    assert(s.singleNonDuplicate(n1) == 2);

    // LeetCode example 2
    std::vector<int> n2 = {3, 3, 7, 7, 10, 11, 11};
    assert(s.singleNonDuplicate(n2) == 10);

    // Single element
    std::vector<int> n3 = {5};
    assert(s.singleNonDuplicate(n3) == 5);

    // Single element at the start
    std::vector<int> n4 = {1, 2, 2, 3, 3};
    assert(s.singleNonDuplicate(n4) == 1);

    // Single element at the end
    std::vector<int> n5 = {1, 1, 2, 2, 3};
    assert(s.singleNonDuplicate(n5) == 3);

    std::cout << "Single Element in a Sorted Array: all tests passed\n";
}
