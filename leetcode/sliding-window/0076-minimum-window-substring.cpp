// 76. Minimum Window Substring (Hard)
// https://leetcode.com/problems/minimum-window-substring/
// Date:       2026-10-30
// Result:     alone | hint | read solution
// Time taken: __ min
//
// Approach, in two lines of my own words:
//
//
// Complexity: time O(n), space O(n)
// C++ I learned:

#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "lc.hpp"

class Solution {
   public:
    std::string minWindow(std::string s, std::string t) {
        if (t.size() > s.size()) return "";
        std::unordered_map<char, int> freq;
        freq.reserve(t.size());

        for (char c : t) {
            freq[c]++;
        }

        int left = 0;
        std::unordered_map<char, int> map;
        map.reserve(t.size());
        int minW = INT_MAX;
        int start = 0;
        int have = 0;
        int need = freq.size();
        int n = s.size();
        for (int right = 0; right < n; right++) {
            char c = s[right];
            if (freq[c]) {
                map[c]++;
                if (map[c] == freq[c]) {
                    have++;
                }
            }

            while (have == need) {
                int window = right - left + 1;
                if (window < minW) {
                    minW = window;
                    start = left;
                }
                char removed = s[left];
                if (freq[removed]) {
                    if (map[removed] == freq[removed]) {
                        have--;
                    }

                    map[removed]--;
                }

                left++;
            }
        }
        return minW == INT_MAX ? "" : s.substr(start, minW);
    }
};

int main() {
    Solution s;

    // LeetCode example 1: "BANC" is the shortest window with A, B and C
    assert(s.minWindow("ADOBECODEBANC", "ABC") == "BANC");

    // LeetCode example 2: the whole string is the window
    assert(s.minWindow("a", "a") == "a");

    // LeetCode example 3: t needs two a's, s only has one
    assert(s.minWindow("a", "aa") == "");

    // Duplicates in t must all be inside the window
    assert(s.minWindow("aabbcc", "abb") == "abb");

    // Uppercase and lowercase are different characters
    assert(s.minWindow("aA", "A") == "A");

    // A character of t is missing from s
    assert(s.minWindow("abc", "d") == "");

    // Order inside the window does not matter
    assert(s.minWindow("abc", "cba") == "abc");

    // Best window is at the very end
    assert(s.minWindow("bba", "ab") == "ba");

    std::cout << "Minimum Window Substring: all tests passed\n";
}
