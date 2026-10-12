// 739. Daily Temperatures (Medium)
// https://leetcode.com/problems/daily-temperatures/
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
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int n = temperatures.size();
        std::vector<int> res(n);
        std::stack<int> st;

        for (int i = 0; i < n; i++) {
            int currTemp = temperatures[i];
            while (!st.empty() && temperatures[st.top()] < currTemp) {
                int j = st.top();
                res[j] = i - j;
                st.pop();
            }
            st.push(i);
        }

        return res;
    }
};

int main() {
    Solution s;

    // LeetCode example 1: mixed rises and drops
    std::vector<int> t1 = {73, 74, 75, 71, 69, 72, 76, 73};
    assert(s.dailyTemperatures(t1) == std::vector<int>({1, 1, 4, 2, 1, 1, 0, 0}));

    // LeetCode example 2: always rising
    std::vector<int> t2 = {30, 40, 50, 60};
    assert(s.dailyTemperatures(t2) == std::vector<int>({1, 1, 1, 0}));

    // LeetCode example 3
    std::vector<int> t3 = {30, 60, 90};
    assert(s.dailyTemperatures(t3) == std::vector<int>({1, 1, 0}));

    // Single day: no warmer day ahead
    std::vector<int> t4 = {50};
    assert(s.dailyTemperatures(t4) == std::vector<int>({0}));

    // Always falling: every answer is 0
    std::vector<int> t5 = {90, 80, 70};
    assert(s.dailyTemperatures(t5) == std::vector<int>({0, 0, 0}));

    // Equal temperatures are not warmer
    std::vector<int> t6 = {70, 70, 71};
    assert(s.dailyTemperatures(t6) == std::vector<int>({2, 1, 0}));

    std::cout << "Daily Temperatures: all tests passed\n";
}
