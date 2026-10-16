// 853. Car Fleet (Medium)
// https://leetcode.com/problems/car-fleet/
// Date:       2026-10-16
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
#include <utility>
#include <vector>

#include "lc.hpp"

class Solution {
   public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        std::vector<std::pair<int, int>> cars;
        int n = position.size();

        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        // closest to target first
        std::sort(cars.rbegin(), cars.rend());

        std::stack<double> st;

        for (auto& [pos, spd] : cars) {
            double time = (double)(target - pos) / spd;

            // catches the fleet ahead, joins it
            if (!st.empty() && time <= st.top()) {
                continue;
            }

            st.push(time);
        }

        return st.size();
    }
};

int main() {
    Solution s;

    // LeetCode example 1: three fleets
    std::vector<int> p1 = {10, 8, 0, 5, 3}, s1 = {2, 4, 1, 1, 3};
    assert(s.carFleet(12, p1, s1) == 3);

    // LeetCode example 2: single car
    std::vector<int> p2 = {3}, s2 = {3};
    assert(s.carFleet(10, p2, s2) == 1);

    // LeetCode example 3: everyone merges into one fleet
    std::vector<int> p3 = {0, 2, 4}, s3 = {4, 2, 1};
    assert(s.carFleet(100, p3, s3) == 1);

    // Car behind is slower, never catches up
    std::vector<int> p4 = {0, 5}, s4 = {1, 2};
    assert(s.carFleet(10, p4, s4) == 2);

    // Catches up exactly at the target, counts as one fleet
    std::vector<int> p5 = {0, 5}, s5 = {2, 1};
    assert(s.carFleet(10, p5, s5) == 1);

    std::cout << "Car Fleet: all tests passed\n";
}
