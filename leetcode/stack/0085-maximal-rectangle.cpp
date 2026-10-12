// 85. Maximal Rectangle (Hard)
// https://leetcode.com/problems/maximal-rectangle/
// Date:       2026-10-12
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
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        int best = 0;
        int rows = matrix.size();
        int n = matrix[0].size();
        std::vector<int> heights(n);

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] == '1') {
                    heights[col]++;
                } else {
                    heights[col] = 0;
                }
            }
            std::stack<int> st;
            for (int col = 0; col <= n; col++) {
                int currHeight = (col == n) ? 0 : heights[col];

                while (!st.empty() && heights[st.top()] > currHeight) {
                    int height = heights[st.top()];
                    st.pop();

                    int width = st.empty() ? col : col - st.top() - 1;
                    best = std::max(best, height * width);
                }

                st.push(col);
            }
        }

        return best;
    }
};

int main() {
    Solution s;

    // LeetCode example 1: best is the 2x3 block in rows 1-2
    std::vector<std::vector<char>> m1 = {{'1', '0', '1', '0', '0'},
                                         {'1', '0', '1', '1', '1'},
                                         {'1', '1', '1', '1', '1'},
                                         {'1', '0', '0', '1', '0'}};
    assert(s.maximalRectangle(m1) == 6);

    // LeetCode example 2: no ones
    std::vector<std::vector<char>> m2 = {{'0'}};
    assert(s.maximalRectangle(m2) == 0);

    // LeetCode example 3: single one
    std::vector<std::vector<char>> m3 = {{'1'}};
    assert(s.maximalRectangle(m3) == 1);

    // All ones: the whole grid
    std::vector<std::vector<char>> m4 = {{'1', '1', '1'}, {'1', '1', '1'}};
    assert(s.maximalRectangle(m4) == 6);

    // Single row: longest run of ones
    std::vector<std::vector<char>> m5 = {{'1', '1', '0', '1', '1', '1'}};
    assert(s.maximalRectangle(m5) == 3);

    // Single column broken by a zero
    std::vector<std::vector<char>> m6 = {{'1'}, {'1'}, {'0'}, {'1'}};
    assert(s.maximalRectangle(m6) == 2);

    std::cout << "Maximal Rectangle: all tests passed\n";
}
