// 658. Find K Closest Elements (Medium)
// https://leetcode.com/problems/find-k-closest-elements/
// Date:       2026-10-20
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
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "lc.hpp"

class Solution {
   public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
        int low = 0;
        int high = arr.size() - 1;

        while (high - low + 1 > k) {
            if (std::abs(arr[high] - x) < std::abs(arr[low] - x)) {
                low++;
            } else {
                high--;
            }
        }

        return std::vector<int>(arr.begin() + low, arr.begin() + high + 1);
    }
};

int main() {
    Solution s;

    // LeetCode example 1
    std::vector<int> a1 = {1, 2, 3, 4, 5};
    assert(s.findClosestElements(a1, 4, 3) == std::vector<int>({1, 2, 3, 4}));

    // LeetCode example 2
    std::vector<int> a2 = {1, 1, 2, 3, 4, 5};
    assert(s.findClosestElements(a2, 4, -1) == std::vector<int>({1, 1, 2, 3}));

    // x past the end
    std::vector<int> a3 = {1, 2, 3, 4, 5};
    assert(s.findClosestElements(a3, 2, 10) == std::vector<int>({4, 5}));

    // Tie goes to the smaller element
    std::vector<int> a4 = {1, 3};
    assert(s.findClosestElements(a4, 1, 2) == std::vector<int>({1}));

    // k equals the array size
    std::vector<int> a5 = {1, 2, 3};
    assert(s.findClosestElements(a5, 3, 2) == std::vector<int>({1, 2, 3}));

    std::cout << "Find K Closest Elements: all tests passed\n";
}
