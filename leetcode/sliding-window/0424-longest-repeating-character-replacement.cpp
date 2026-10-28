// 424. Longest Repeating Character Replacement (Medium)
// https://leetcode.com/problems/longest-repeating-character-replacement/
// Date:       2026-10-28
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
    int characterReplacement(std::string s, int k) {
        int left = 0;
        std::unordered_map<char, int> freq;

        int maxFreq = 0;
        int maxV = 0;
        int n = s.size();

        for (int right = 0; right < n; right++) {
            freq[s[right]]++;

            maxFreq = std::max(maxFreq, freq[s[right]]);

            while ((right - left + 1) - maxFreq > k) {
                freq[s[left]]--;
                left++;
            }
            maxV = std::max(maxV, right - left + 1);
        }
        return maxV;
    }
};

int main() {
    Solution s;

    // LeetCode example 1: replace both A's (or both B's)
    assert(s.characterReplacement("ABAB", 2) == 4);

    // LeetCode example 2: replace one A to get "BBBB"
    assert(s.characterReplacement("AABABBA", 1) == 4);

    // k = 0: longest run as it is
    assert(s.characterReplacement("AABBBA", 0) == 3);

    // Single character
    assert(s.characterReplacement("A", 0) == 1);

    // k covers the whole string
    assert(s.characterReplacement("ABCD", 4) == 4);

    // All the same character
    assert(s.characterReplacement("AAAA", 2) == 4);

    std::cout << "Longest Repeating Character Replacement: all tests passed\n";
}
