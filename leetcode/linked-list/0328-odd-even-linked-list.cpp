// 328. Odd Even Linked List (Medium)
// https://leetcode.com/problems/odd-even-linked-list/
// Date:       2026-10-23
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};

int main() {
    Solution s;

    // LeetCode example 1: odd length
    ListNode* l1 = s.oddEvenList(lc::make_list({1, 2, 3, 4, 5}));
    assert(lc::to_vector(l1) == std::vector<int>({1, 3, 5, 2, 4}));
    lc::free_list(l1);

    // LeetCode example 2: groups by position, not by value
    ListNode* l2 = s.oddEvenList(lc::make_list({2, 1, 3, 5, 6, 4, 7}));
    assert(lc::to_vector(l2) == std::vector<int>({2, 3, 6, 7, 1, 5, 4}));
    lc::free_list(l2);

    // Empty list
    assert(s.oddEvenList(nullptr) == nullptr);

    // Single node stays put
    ListNode* l4 = s.oddEvenList(lc::make_list({1}));
    assert(lc::to_vector(l4) == std::vector<int>({1}));
    lc::free_list(l4);

    // Two nodes already in order
    ListNode* l5 = s.oddEvenList(lc::make_list({1, 2}));
    assert(lc::to_vector(l5) == std::vector<int>({1, 2}));
    lc::free_list(l5);

    // Even length
    ListNode* l6 = s.oddEvenList(lc::make_list({1, 2, 3, 4}));
    assert(lc::to_vector(l6) == std::vector<int>({1, 3, 2, 4}));
    lc::free_list(l6);

    std::cout << "Odd Even Linked List: all tests passed\n";
}
