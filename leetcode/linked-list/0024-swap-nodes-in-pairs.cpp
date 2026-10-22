// 24. Swap Nodes in Pairs (Medium)
// https://leetcode.com/problems/swap-nodes-in-pairs/
// Date:       2026-10-22
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = &dummy;

        while (curr->next && curr->next->next) {
            ListNode* first = curr->next;
            ListNode* second = first->next;
            first->next = second->next;
            second->next = first;
            curr->next = second;

            curr = first;
        }

        return dummy.next;
    }
};

int main() {
    Solution s;

    // LeetCode example 1: even length
    ListNode* l1 = s.swapPairs(lc::make_list({1, 2, 3, 4}));
    assert(lc::to_vector(l1) == std::vector<int>({2, 1, 4, 3}));
    lc::free_list(l1);

    // LeetCode example 2: empty list
    assert(s.swapPairs(nullptr) == nullptr);

    // LeetCode example 3: single node stays put
    ListNode* l3 = s.swapPairs(lc::make_list({1}));
    assert(lc::to_vector(l3) == std::vector<int>({1}));
    lc::free_list(l3);

    // LeetCode example 4: odd length, last node stays put
    ListNode* l4 = s.swapPairs(lc::make_list({1, 2, 3}));
    assert(lc::to_vector(l4) == std::vector<int>({2, 1, 3}));
    lc::free_list(l4);

    // Just one pair
    ListNode* l5 = s.swapPairs(lc::make_list({7, 9}));
    assert(lc::to_vector(l5) == std::vector<int>({9, 7}));
    lc::free_list(l5);

    std::cout << "Swap Nodes in Pairs: all tests passed\n";
}
