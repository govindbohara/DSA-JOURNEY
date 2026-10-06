// 763. Partition Labels (Medium)
// https://leetcode.com/problems/partition-labels/
// Date:       2026-10-06
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
    std::vector<int> partitionLabels(std::string s) {
        int last[26]{};

        std::vector<int> result;
        result.reserve(26);

        for (int i = 0; i < s.length(); i++) {
            last[s[i] - 'a'] = i;
        }

        int left = 0;
        int right = 0;

        for (int i = 0; i < s.length(); i++) {
            right = std::max(right, last[s[i] - 'a']);

            if (i == right) {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};

int main() {
    Solution s;

    // LeetCode example 1: "ababcbaca", "defegde", "hijhklij"
    assert(s.partitionLabels("ababcbacadefegdehijhklij") == std::vector<int>({9, 7, 8}));

    // LeetCode example 2: 'e' at both ends forces one partition
    assert(s.partitionLabels("eccbbbbdec") == std::vector<int>({10}));

    // Single character
    assert(s.partitionLabels("a") == std::vector<int>({1}));

    // All distinct: every letter is its own partition
    assert(s.partitionLabels("abc") == std::vector<int>({1, 1, 1}));

    // All the same letter: one partition
    assert(s.partitionLabels("aaaa") == std::vector<int>({4}));

    // Same first and last letter swallows everything in between
    assert(s.partitionLabels("abca") == std::vector<int>({4}));

    // Partition grows: 'a' reaches index 3, then 'b' inside it doesn't go further
    assert(s.partitionLabels("abbacd") == std::vector<int>({4, 1, 1}));

    // End gets pushed out while scanning: 'a' ends at 2, but 'b' extends it to 4
    assert(s.partitionLabels("abacbdd") == std::vector<int>({5, 2}));

    // Lone first letter, then the rest is tied together by 'a' and 'd'
    assert(s.partitionLabels("caedbdedda") == std::vector<int>({1, 9}));

    std::cout << "Partition Labels: all tests passed\n";
}
