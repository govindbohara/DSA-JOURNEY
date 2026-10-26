// 86. Partition List (Medium)
// https://leetcode.com/problems/partition-list/
// Date:       2026-10-26
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* curr = head;
        ListNode* smallList = new ListNode(0);
        ListNode* largeList = new ListNode(0);

        ListNode* smallTail = smallList;
        ListNode* largeTail = largeList;

        while (curr != nullptr) {
            if (curr->val < x) {
                smallTail->next = curr;
                smallTail = smallTail->next;
            } else {
                largeTail->next = curr;
                largeTail = largeTail->next;
            }
            curr = curr->next;
        }

        largeTail->next = nullptr;
        smallTail->next = largeList->next;
        return smallList->next;
    }
};

int main() {
    [[maybe_unused]] Solution s;

    // LeetCode's examples, plus at least one edge case of my own:
    // assert(s.method(input) == expected);

    std::cout << "Partition List: all tests passed\n";
}
