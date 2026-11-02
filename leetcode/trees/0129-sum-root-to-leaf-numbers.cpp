// 129. Sum Root to Leaf Numbers (Medium)
// https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Date:       2026-11-02
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
    int totalSum = 0;
    void dfs(TreeNode* root, int sum) {
        if (root == nullptr) return;

        sum = (sum * 10) + root->val;

        if (root->left == nullptr && root->right == nullptr) {
            totalSum += sum;
            return;
        }

        dfs(root->left, sum);
        dfs(root->right, sum);
    }
    int sumNumbers(TreeNode* root) {
        totalSum = 0;
        dfs(root, 0);
        return totalSum;
    }
};

int main() {
    Solution s;
    constexpr auto null = std::nullopt;

    // LeetCode example 1: 12 + 13 = 25
    TreeNode* example1 = lc::make_tree({1, 2, 3});
    assert(s.sumNumbers(example1) == 25);
    lc::free_tree(example1);

    // LeetCode example 2: 495 + 491 + 40 = 1026
    TreeNode* example2 = lc::make_tree({4, 9, 0, 5, 1});
    assert(s.sumNumbers(example2) == 1026);
    lc::free_tree(example2);

    // A single node is both the root and a leaf
    TreeNode* single = lc::make_tree({7});
    assert(s.sumNumbers(single) == 7);
    lc::free_tree(single);

    // A lone zero is still one number
    TreeNode* zero = lc::make_tree({0});
    assert(s.sumNumbers(zero) == 0);
    lc::free_tree(zero);

    // Leading zero: 0 -> 1 is the number 1
    TreeNode* leadingZero = lc::make_tree({0, 1});
    assert(s.sumNumbers(leadingZero) == 1);
    lc::free_tree(leadingZero);

    // Node with one child is not a leaf, so the missing side adds nothing: only 12 counts
    TreeNode* rightOnly = lc::make_tree({1, null, 2});
    assert(s.sumNumbers(rightOnly) == 12);
    lc::free_tree(rightOnly);

    // Uneven depths: 124 + 13 = 137
    TreeNode* uneven = lc::make_tree({1, 2, 3, 4});
    assert(s.sumNumbers(uneven) == 137);
    lc::free_tree(uneven);

    std::cout << "Sum Root to Leaf Numbers: all tests passed\n";
}
