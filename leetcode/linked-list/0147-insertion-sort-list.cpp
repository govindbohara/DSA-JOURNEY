// 147. Insertion Sort List (Medium)
// https://leetcode.com/problems/insertion-sort-list/
// Date:       2026-10-27
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            ListNode* prev = &dummy;

            while (prev->next != nullptr && prev->next->val <= curr->val) {
                prev = prev->next;
            }

            curr->next = prev->next;
            prev->next = curr;

            curr = nextNode;
        }
        return dummy.next;
    }
};

int main() {
    [[maybe_unused]] Solution s;

    // LeetCode's examples, plus at least one edge case of my own:
    // assert(s.method(input) == expected);

    std::cout << "Insertion Sort List: all tests passed\n";
}
