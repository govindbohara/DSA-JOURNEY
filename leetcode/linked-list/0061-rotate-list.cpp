// 61. Rotate List (Medium)
// https://leetcode.com/problems/rotate-list/
// Date:       2026-10-24
// Result:     alone | hint | read solution
// Time taken: __ min
//
// Approach, in two lines of my own words:
// Walk to the tail to get the length, reduce k mod length, then cut after
// node (length - k) and splice the old tail onto the old head.
// Complexity: time O(n), space O(1)
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        ListNode* curr = head;
        int length = 0;

        while (curr != nullptr) {
            curr = curr->next;
            length++;
        }

        k = k % length;

        if (k == 0) return head;

        curr = head;
        for (int i = 0; i < length - k - 1; i++) {
            curr = curr->next;
        }
        ListNode* extendedHead = curr->next;
        curr->next = nullptr;
        ListNode* extendedNode = extendedHead;

        while (extendedNode->next != nullptr) {
            extendedNode = extendedNode->next;
        }

        extendedNode->next = head;

        return extendedHead;
    }
};

int main() {
    Solution s;

    // LeetCode example 1
    ListNode* l1 = s.rotateRight(lc::make_list({1, 2, 3, 4, 5}), 2);
    assert(lc::to_vector(l1) == std::vector<int>({4, 5, 1, 2, 3}));
    lc::free_list(l1);

    // LeetCode example 2: k larger than the length wraps around
    ListNode* l2 = s.rotateRight(lc::make_list({0, 1, 2}), 4);
    assert(lc::to_vector(l2) == std::vector<int>({2, 0, 1}));
    lc::free_list(l2);

    // Empty list
    assert(s.rotateRight(nullptr, 3) == nullptr);

    // k == 0 leaves the list unchanged
    ListNode* l4 = s.rotateRight(lc::make_list({1, 2, 3}), 0);
    assert(lc::to_vector(l4) == std::vector<int>({1, 2, 3}));
    lc::free_list(l4);

    // k is a multiple of the length
    ListNode* l5 = s.rotateRight(lc::make_list({1, 2, 3}), 6);
    assert(lc::to_vector(l5) == std::vector<int>({1, 2, 3}));
    lc::free_list(l5);

    // Single node
    ListNode* l6 = s.rotateRight(lc::make_list({7}), 5);
    assert(lc::to_vector(l6) == std::vector<int>({7}));
    lc::free_list(l6);

    std::cout << "Rotate List: all tests passed\n";
}
