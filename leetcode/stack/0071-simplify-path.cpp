// 71. Simplify Path (Medium)
// https://leetcode.com/problems/simplify-path/
// Date:       2026-10-08
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
#include <ranges>
#include <stack>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "lc.hpp"

class Solution {
   public:
    std::string simplifyPath(std::string path) {
        std::stack<std::string> st;

        for (const auto& subrange : std::views::split(path, '/')) {
            std::string_view word(subrange.begin(), subrange.end());

            if (word == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else if (word == "." || word.empty()) {
                continue;
            } else {
                st.push(std::string(word));
            }
        }

        // Reverse the stack
        std::stack<std::string> reversed;

        while (!st.empty()) {
            reversed.push(st.top());
            st.pop();
        }

        // Build result from left to right
        std::string res;

        while (!reversed.empty()) {
            res += "/";
            res += reversed.top();
            reversed.pop();
        }

        return res.empty() ? "/" : res;
    }
};

int main() {
    Solution s;

    // LeetCode example 1: trailing slash removed
    assert(s.simplifyPath("/home/") == "/home");

    // LeetCode example 2: repeated slashes become one
    assert(s.simplifyPath("/home//foo/") == "/home/foo");

    // LeetCode example 3: ".." goes up one directory
    assert(s.simplifyPath("/home/user/Documents/../Pictures") == "/home/user/Pictures");

    // LeetCode example 4: ".." at root stays at root
    assert(s.simplifyPath("/../") == "/");

    // LeetCode example 5: "..." is a real directory name, not a command
    assert(s.simplifyPath("/.../a/../b/c/../d/./") == "/.../b/d");

    // Root only
    assert(s.simplifyPath("/") == "/");

    // "." means stay, ".." twice climbs back to root before "c"
    assert(s.simplifyPath("/a/./b/../../c/") == "/c");

    // Names that start with dots are still normal names
    assert(s.simplifyPath("/..hidden/.x") == "/..hidden/.x");

    // More ".." than directories: can't go above root
    assert(s.simplifyPath("/a/b/c/../../../..") == "/");

    std::cout << "Simplify Path: all tests passed\n";
}
