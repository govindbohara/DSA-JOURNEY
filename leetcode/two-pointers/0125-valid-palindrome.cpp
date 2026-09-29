// 125. Valid Palindrome (Easy)
// https://leetcode.com/problems/valid-palindrome/
// Date:       2026-09-29
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
    bool isPalindrome(std::string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;

            if (tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }

        return true;
    }
};

int main() {
    Solution s;

    // LeetCode examples
    assert(s.isPalindrome("A man, a plan, a canal: Panama") == true);
    assert(s.isPalindrome("race a car") == false);
    assert(s.isPalindrome(" ") == true);  // empty after cleaning

    // Only punctuation: also empty after cleaning
    assert(s.isPalindrome(".,") == true);

    // Digits count and are not letters: '0' != 'p'
    assert(s.isPalindrome("0P") == false);

    // Underscore is not alphanumeric, so it is skipped
    assert(s.isPalindrome("ab_a") == true);

    // Single character and mixed case
    assert(s.isPalindrome("a") == true);
    assert(s.isPalindrome("No 'x' in Nixon") == true);

    std::cout << "Valid Palindrome: all tests passed\n";
}
