// 113. Path Sum II (Medium)
// https://leetcode.com/problems/path-sum-ii/
// Date:       2026-10-31
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
    std::vector<std::vector<int>> res;
    void dfs(TreeNode* node, int target, int sum, std::vector<int>& path) {
        if (node == nullptr) {
            return;
        }
        sum += node->val;
        path.push_back(node->val);

        if (node->left == nullptr && node->right == nullptr) {
            if (sum == target) {
                res.push_back(path);
            }
        }
        dfs(node->left, target, sum, path);
        dfs(node->right, target, sum, path);

        path.pop_back();
    }
    std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
        res.clear();
        std::vector<int> path;
        dfs(root, targetSum, 0, path);

        return res;
    }
};

int main() {
    Solution s;
    using Paths = std::vector<std::vector<int>>;
    constexpr auto null = std::nullopt;

    // Expected paths are listed left to right, the order a left-first DFS finds them

    // LeetCode example 1: two root-to-leaf paths sum to 22
    TreeNode* example1 = lc::make_tree({5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1});
    assert((s.pathSum(example1, 22) == Paths{{5, 4, 11, 2}, {5, 8, 4, 5}}));
    lc::free_tree(example1);

    // LeetCode example 2: no path sums to 5
    TreeNode* example2 = lc::make_tree({1, 2, 3});
    assert(s.pathSum(example2, 5).empty());
    lc::free_tree(example2);

    // LeetCode example 3: no path sums to 0
    TreeNode* example3 = lc::make_tree({1, 2});
    assert(s.pathSum(example3, 0).empty());
    lc::free_tree(example3);

    // Empty tree has no paths, even when the target is 0
    assert(s.pathSum(nullptr, 0).empty());

    // A single node is both the root and a leaf
    TreeNode* single = lc::make_tree({7});
    assert((s.pathSum(single, 7) == Paths{{7}}));
    lc::free_tree(single);

    // The sum reaches 1 at the root, but the path must end at a leaf
    TreeNode* notLeaf = lc::make_tree({1, 2});
    assert(s.pathSum(notLeaf, 1).empty());
    lc::free_tree(notLeaf);

    // Negative values mean the sum can overshoot and come back
    TreeNode* negatives = lc::make_tree({1, -2, -3, 1, 3, -2, null, -1});
    assert((s.pathSum(negatives, -1) == Paths{{1, -2, 1, -1}}));
    lc::free_tree(negatives);

    std::cout << "Path Sum II: all tests passed\n";
}
