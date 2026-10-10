// 394. Decode String (Medium)
// https://leetcode.com/problems/decode-string/
// Date:       2026-10-08
// Result:     alone | hint | read solution
// Time taken: __ min
//
// Approach, in two lines of my own words:
// On '[' push the count and the string built so far, then start fresh.
// On ']' pop them and set curr = saved + curr repeated count times.
// Complexity: time O(n + output length), space O(n + output length)
// C++ I learned: std::stack, std::isdigit, num = num * 10 + (c - '0')

#include <algorithm>
#include <cassert>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "lc.hpp"

class Solution {
   public:
    std::string decodeString(std::string s) {
        std::stack<int> nums;
        std::stack<std::string> strs;

        std::string curr = "";
        int num = 0;

        for (char c : s) {
            if (std::isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            else if (c == '[') {
                nums.push(num);
                strs.push(curr);

                num = 0;
                curr = "";
            }

            else if (c == ']') {
                int repeat = nums.top();
                nums.pop();

                std::string prev = strs.top();
                strs.pop();

                std::string temp = "";

                for (int i = 0; i < repeat; i++) {
                    temp += curr;
                }

                curr = prev + temp;
            }

            else {
                curr += c;
            }
        }

        return curr;
    }
};

int main() {
    Solution s;

    // LeetCode example 1: two groups side by side
    assert(s.decodeString("3[a]2[bc]") == "aaabcbc");

    // LeetCode example 2: nested group
    assert(s.decodeString("3[a2[c]]") == "accaccacc");

    // LeetCode example 3: plain letters after the groups
    assert(s.decodeString("2[abc]3[cd]ef") == "abcabccdcdcdef");

    // No brackets at all: std::string comes back unchanged
    assert(s.decodeString("abc") == "abc");

    // Multi-digit count: must read "10", not just "0"
    assert(s.decodeString("10[a]") == "aaaaaaaaaa");

    // Count of 1
    assert(s.decodeString("1[a]") == "a");

    // Letters before, inside and after a group
    assert(s.decodeString("ab2[c]d") == "abccd");

    // Three levels deep
    assert(s.decodeString("2[a2[b3[c]]]") == "abcccbcccabcccbccc");

    // Letters mixed with a nested group inside a group
    assert(s.decodeString("2[x3[y]z]") == "xyyyzxyyyz");

    std::cout << "Decode String: all tests passed\n";
}
