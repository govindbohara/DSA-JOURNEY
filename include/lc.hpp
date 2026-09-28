#pragma once
// LeetCode's node types, plus helpers to build test inputs and free them.
// Always free what you build: AddressSanitizer reports leaks as failures.

#include <cstddef>
#include <optional>
#include <queue>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

namespace lc {

// {1,2,3} -> 1->2->3
inline ListNode* make_list(const std::vector<int>& values) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int v : values) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

inline std::vector<int> to_vector(const ListNode* head) {
    std::vector<int> out;
    for (; head != nullptr; head = head->next) out.push_back(head->val);
    return out;
}

// Break any cycle before calling this, or it never finishes.
inline void free_list(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

// Level order, like LeetCode's [3,9,20,null,null,15,7].
// Write it as: lc::make_tree({3, 9, 20, std::nullopt, std::nullopt, 15, 7})
inline TreeNode* make_tree(const std::vector<std::optional<int>>& values) {
    if (values.empty() || !values[0]) return nullptr;
    TreeNode* root = new TreeNode(*values[0]);
    std::queue<TreeNode*> pending;
    pending.push(root);
    std::size_t i = 1;
    while (!pending.empty() && i < values.size()) {
        TreeNode* node = pending.front();
        pending.pop();
        if (i < values.size() && values[i]) {
            node->left = new TreeNode(*values[i]);
            pending.push(node->left);
        }
        ++i;
        if (i < values.size() && values[i]) {
            node->right = new TreeNode(*values[i]);
            pending.push(node->right);
        }
        ++i;
    }
    return root;
}

inline void free_tree(TreeNode* root) {
    if (root == nullptr) return;
    free_tree(root->left);
    free_tree(root->right);
    delete root;
}

}  // namespace lc
