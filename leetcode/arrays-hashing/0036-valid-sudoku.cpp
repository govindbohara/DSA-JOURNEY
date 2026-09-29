// 36. Valid Sudoku (Medium)
// https://leetcode.com/problems/valid-sudoku/
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
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        int rows[9][9]{}, cols[9][9]{}, boxes[9][9]{};
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[row].size(); col++) {
                if (board[row][col] == '.') continue;
                const int& val = board[row][col] - '1';
                std::cout << " " << val;

                int boxId = (row / 3) * 3 + (col / 3);
                if (rows[row][val]) return false;
                if (cols[col][val]) return false;
                if (boxes[boxId][val]) return false;

                rows[row][val] = 1;
                cols[col][val] = 1;
                boxes[boxId][val] = 1;
            }
        }

        return true;
    }
};

// Builds a board from 9 strings so the tests are easy to read.
std::vector<std::vector<char>> makeBoard(const std::vector<std::string>& rows) {
    std::vector<std::vector<char>> board;
    for (const std::string& row : rows) {
        board.emplace_back(row.begin(), row.end());
    }
    return board;
}

int main() {
    Solution s;

    // LeetCode example 1: valid
    auto a = makeBoard({
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79",
    });
    assert(s.isValidSudoku(a) == true);

    // LeetCode example 2: two 8s in the top-left box (and column 0)
    auto b = makeBoard({
        "83..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79",
    });
    assert(s.isValidSudoku(b) == false);

    // Empty board is valid
    auto c = makeBoard({
        ".........",
        ".........",
        ".........",
        ".........",
        ".........",
        ".........",
        ".........",
        ".........",
        ".........",
    });
    assert(s.isValidSudoku(c) == true);

    // Duplicate only in a row (different columns and boxes)
    auto d = c;
    d[0][0] = '1';
    d[0][8] = '1';
    assert(s.isValidSudoku(d) == false);

    // Duplicate only in a column (different rows and boxes)
    auto e = c;
    e[0][0] = '1';
    e[8][0] = '1';
    assert(s.isValidSudoku(e) == false);

    // Duplicate only in the centre box (different rows and columns)
    auto f = c;
    f[4][4] = '5';
    f[5][3] = '5';
    assert(s.isValidSudoku(f) == false);

    // Same digit in different rows, columns and boxes is fine
    auto g = c;
    g[0][0] = '9';
    g[4][4] = '9';
    g[8][8] = '9';
    assert(s.isValidSudoku(g) == true);

    std::cout << "Valid Sudoku: all tests passed\n";
}
