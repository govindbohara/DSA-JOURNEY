// 162. Find Peak Element (Medium)
// https://leetcode.com/problems/find-peak-element/
// Date:       2026-10-18
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
    int findPeakElement(std::vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 2;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int midNum = nums[mid];

            if (nums[mid - 1] < midNum && midNum > nums[mid + 1]) {
                return mid;
            } else if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (nums.size() == 1 || nums[0] > nums[1]) {
            return 0;
        }

        return nums.size() - 1;
    }
};

// Any peak is accepted, so check the returned index instead of a fixed answer
bool isPeak(const std::vector<int>& nums, int i) {
    int n = nums.size();
    if (i < 0 || i >= n) return false;
    bool leftOk = i == 0 || nums[i - 1] < nums[i];
    bool rightOk = i == n - 1 || nums[i] > nums[i + 1];
    return leftOk && rightOk;
}

int main() {
    Solution s;

    // LeetCode example 1: peak at index 2
    std::vector<int> n1 = {1, 2, 3, 1};
    assert(s.findPeakElement(n1) == 2);

    // LeetCode example 2: peaks at 1 or 5, either is fine
    std::vector<int> n2 = {1, 2, 1, 3, 5, 6, 4};
    assert(isPeak(n2, s.findPeakElement(n2)));

    // Single element is a peak
    std::vector<int> n3 = {7};
    assert(s.findPeakElement(n3) == 0);

    // Two elements, peak on either side
    std::vector<int> n4 = {2, 1}, n5 = {1, 2};
    assert(s.findPeakElement(n4) == 0);
    assert(s.findPeakElement(n5) == 1);

    // Strictly increasing: peak at the end
    std::vector<int> n6 = {1, 2, 3, 4, 5};
    assert(s.findPeakElement(n6) == 4);

    // Strictly decreasing: peak at the start
    std::vector<int> n7 = {5, 4, 3, 2, 1};
    assert(s.findPeakElement(n7) == 0);

    std::cout << "Find Peak Element: all tests passed\n";
}
