// 402. Remove K Digits (Medium)
// https://leetcode.com/problems/remove-k-digits/
// Date:       2026-10-11
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
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "lc.hpp"

class Solution {
   public:
    std::string removeKdigits(std::string num, int k) {
        std::stack<char> st;
        for (char c : num) {
            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }
        while (k > 0) {
            st.pop();
            k--;
        }
        std::string ans;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        std::reverse(ans.begin(), ans.end());

        std::size_t i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }
        ans = ans.substr(i);
        return ans.empty() ? "0" : ans;
    }
};

int main() {
    Solution s;

    // LeetCode example 1: drop the bigger digits that come before smaller ones
    assert(s.removeKdigits("1432219", 3) == "1219");

    // LeetCode example 2: leading zeros are stripped
    assert(s.removeKdigits("10200", 1) == "200");

    // LeetCode example 3: removing every digit leaves "0"
    assert(s.removeKdigits("10", 2) == "0");

    // Increasing digits: nothing gets popped, so remove from the end
    assert(s.removeKdigits("12345", 2) == "123");

    // k = 0: number comes back unchanged
    assert(s.removeKdigits("9", 0) == "9");

    // Every digit after the first is zero
    assert(s.removeKdigits("100000", 1) == "0");

    std::cout << "Remove K Digits: all tests passed\n";
}
