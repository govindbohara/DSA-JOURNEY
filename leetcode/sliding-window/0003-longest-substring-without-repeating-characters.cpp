// 3. Longest Substring Without Repeating Characters (Medium)
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
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
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> seen;
        int maxV = 0;
        int l = 0;
        int n = s.size();
        for (int r = 0; r < n; r++) {
            char c = s[r];
            while (seen.contains(c)) {
                seen.erase(s[l]);
                l++;
            }
            maxV = std::max(maxV, r - l + 1);
            seen.insert(c);
        }
        return maxV;
    }
};

int main() {
    Solution s;

    // LeetCode example 1: "abc"
    assert(s.lengthOfLongestSubstring("abcabcbb") == 3);

    // LeetCode example 2: all the same character
    assert(s.lengthOfLongestSubstring("bbbbb") == 1);

    // LeetCode example 3: "wke", not the subsequence "pwke"
    assert(s.lengthOfLongestSubstring("pwwkew") == 3);

    // Empty string
    assert(s.lengthOfLongestSubstring("") == 0);

    // Spaces count as characters
    assert(s.lengthOfLongestSubstring(" ") == 1);

    // Left must jump past the earlier 'd', not just one step
    assert(s.lengthOfLongestSubstring("dvdf") == 3);

    // Window shrinks past the first b, then a repeats
    assert(s.lengthOfLongestSubstring("abba") == 2);

    std::cout << "Longest Substring Without Repeating Characters: all tests passed\n";
}
