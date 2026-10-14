// 904. Fruit Into Baskets (Medium)
// https://leetcode.com/problems/fruit-into-baskets/
// Date:       2026-10-14
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
    int totalFruit(std::vector<int>& fruits) {
        int left = 0;
        int maxFruit = 0;

        std::unordered_map<int, int> count;
        int n = fruits.size();

        for (int right = 0; right < n; right++) {
            count[fruits[right]]++;
            while (count.size() > 2) {
                count[fruits[left]]--;
                if (count[fruits[left]] == 0) count.erase(fruits[left]);
                left++;
            }
            maxFruit = std::max(maxFruit, right - left + 1);
        }
        return maxFruit;
    }
};

int main() {
    Solution s;

    // LeetCode example 1: only two types, take everything
    std::vector<int> f1 = {1, 2, 1};
    assert(s.totalFruit(f1) == 3);

    // LeetCode example 2: skip the first tree
    std::vector<int> f2 = {0, 1, 2, 2};
    assert(s.totalFruit(f2) == 3);

    // LeetCode example 3: [2, 3, 2, 2]
    std::vector<int> f3 = {1, 2, 3, 2, 2};
    assert(s.totalFruit(f3) == 4);

    // Single tree
    std::vector<int> f4 = {5};
    assert(s.totalFruit(f4) == 1);

    // One type only
    std::vector<int> f5 = {7, 7, 7, 7};
    assert(s.totalFruit(f5) == 4);

    // Best window [1, 2, 1, 1, 2] sits in the middle
    std::vector<int> f6 = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    assert(s.totalFruit(f6) == 5);

    std::cout << "Fruit Into Baskets: all tests passed\n";
}
