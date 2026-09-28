// 238. Product of Array Except Self (Medium)
// https://leetcode.com/problems/product-of-array-except-self/
// Date:       2026-09-25
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

class Solution {
   public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> out(nums.size());

        int prefix = 1;
        for (int i = 0; i < nums.size(); i++) {
            out[i] = prefix;
            prefix = prefix * nums[i];
        }
        int suffix = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            out[i] *= suffix;
            suffix = suffix * nums[i];
        }
        return out;
    }
};

int main() {
    Solution s;

    // LeetCode example 1
    std::vector<int> nums1{1, 2, 3, 4};
    assert(s.productExceptSelf(nums1) == (std::vector<int>{24, 12, 8, 6}));

    // LeetCode example 2: one zero, so only the zero's slot is non-zero
    std::vector<int> nums2{-1, 1, 0, -3, 3};
    assert(s.productExceptSelf(nums2) == (std::vector<int>{0, 0, 9, 0, 0}));

    // Smallest input (length 2): each answer is the other element
    std::vector<int> nums3{2, 3};
    assert(s.productExceptSelf(nums3) == (std::vector<int>{3, 2}));

    // Two zeros: every product includes at least one zero
    std::vector<int> nums4{0, 4, 0};
    assert(s.productExceptSelf(nums4) == (std::vector<int>{0, 0, 0}));

    // All negatives: signs flip depending on how many are multiplied
    std::vector<int> nums5{-1, -2, -3};
    assert(s.productExceptSelf(nums5) == (std::vector<int>{6, 3, 2}));

    // All ones
    std::vector<int> nums6{1, 1, 1, 1};
    assert(s.productExceptSelf(nums6) == (std::vector<int>{1, 1, 1, 1}));

    std::cout << "Product of Array Except Self: all tests passed\n";
}
