// 1011. Capacity To Ship Packages Within D Days (Medium)
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Date:       2026-10-19
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
    int shipWithinDays(std::vector<int>& weights, int days) {
        int low = *std::max_element(weights.begin(), weights.end());
        int high = 0;
        for (int n : weights) {
            high += n;
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;

            bool b = check(mid, days, weights);
            if (b) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }

    bool check(int capacity, int days, std::vector<int>& weights) {
        int day = 1;
        int load = 0;

        for (int n : weights) {
            if (load + n > capacity) {
                day += 1;
                load = n;
            } else {
                load += n;
            }
        }
        return day <= days;
    }
};

int main() {
    Solution s;

    // LeetCode example 1
    std::vector<int> w1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(s.shipWithinDays(w1, 5) == 15);

    // LeetCode example 2
    std::vector<int> w2 = {3, 2, 2, 4, 1, 4};
    assert(s.shipWithinDays(w2, 3) == 6);

    // LeetCode example 3
    std::vector<int> w3 = {1, 2, 3, 1, 1};
    assert(s.shipWithinDays(w3, 4) == 3);

    // One day: must carry everything at once
    assert(s.shipWithinDays(w1, 1) == 55);

    // As many days as packages: capacity is the heaviest package
    assert(s.shipWithinDays(w1, 10) == 10);

    // Single package
    std::vector<int> w4 = {7};
    assert(s.shipWithinDays(w4, 1) == 7);

    std::cout << "Capacity To Ship Packages Within D Days: all tests passed\n";
}
