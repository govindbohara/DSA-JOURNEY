// 224. Basic Calculator (Hard)
// https://leetcode.com/problems/basic-calculator/
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
    int calculate(std::string s) {
        // Each '(' saves the result so far and the sign in front of it.
        std::stack<int> st;
        int result = 0;
        int num = 0;
        int sign = 1;

        for (char c : s) {
            if (std::isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+' || c == '-') {
                result += sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1;
            } else if (c == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * num;
                num = 0;

                int prevSign = st.top();
                st.pop();
                int prevResult = st.top();
                st.pop();

                result = prevResult + prevSign * result;
            }
        }

        return result + sign * num;
    }
};

int main() {
    Solution s;

    // LeetCode example 1
    assert(s.calculate("1 + 1") == 2);

    // LeetCode example 2: spaces at both ends
    assert(s.calculate(" 2-1 + 2 ") == 3);

    // LeetCode example 3: nested parentheses
    assert(s.calculate("(1+(4+5+2)-3)+(6+8)") == 23);

    // Single number
    assert(s.calculate("42") == 42);

    // Unary minus at the start
    assert(s.calculate("-2+1") == -1);

    // Minus in front of a group flips everything inside it
    assert(s.calculate("1-(2-3)") == 2);

    // Unary minus inside a group
    assert(s.calculate("-(-2)") == 2);

    // Deep nesting with minus signs
    assert(s.calculate("10-(2-(3-(4-5)))") == 12);

    std::cout << "Basic Calculator: all tests passed\n";
}
