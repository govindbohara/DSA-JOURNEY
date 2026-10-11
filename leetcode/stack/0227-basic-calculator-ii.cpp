// 227. Basic Calculator II (Medium)
// https://leetcode.com/problems/basic-calculator-ii/
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
        std::stack<int> st;
        int num = 0;
        char op = '+';

        for (std::size_t i = 0; i < s.size(); i++) {
            char c = s[i];

            if (std::isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            if ((!std::isdigit(c) && c != ' ') || i == s.size() - 1) {
                if (op == '+') {
                    st.push(num);
                } else if (op == '-') {
                    st.push(-num);
                } else if (op == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                } else if (op == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / num);
                }

                op = c;
                num = 0;
            }
        }

        int result = 0;

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};

int main() {
    Solution s;

    // LeetCode example 1: * runs before +
    assert(s.calculate("3+2*2") == 7);

    // LeetCode example 2: integer division truncates
    assert(s.calculate(" 3/2 ") == 1);

    // LeetCode example 3: spaces everywhere, / before +
    assert(s.calculate(" 3+5 / 2 ") == 5);

    // Single number
    assert(s.calculate("42") == 42);

    // Multi-digit numbers and subtraction
    assert(s.calculate("100-20*3") == 40);

    // Chain of * and / runs left to right
    assert(s.calculate("14/3*2") == 8);

    // Minus before a product: the product is negated
    assert(s.calculate("1-2*3") == -5);

    std::cout << "Basic Calculator II: all tests passed\n";
}
