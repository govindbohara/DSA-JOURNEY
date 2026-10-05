// 881. Boats to Save People (Medium)
// https://leetcode.com/problems/boats-to-save-people/
// Date:       2026-10-05
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
    int numRescueBoats(std::vector<int>& people, int limit) {
        if (people.empty()) return 0;
        std::sort(people.begin(), people.end());
        int minBoat = 0;
        int left = 0;
        int right = people.size() - 1;

        while (left <= right) {
            int rightWeight = people[right];
            int leftWeight = people[left];
            if (leftWeight + rightWeight <= limit) {
                left++;
            }
            minBoat++;
            right--;
        }
        return minBoat;
    }
};

int main() {
    Solution s;

    // LeetCode example 1: one boat carries both people
    std::vector<int> a{1, 2};
    assert(s.numRescueBoats(a, 3) == 1);

    // LeetCode example 2: (1,2), (2), (3)
    std::vector<int> b{3, 2, 2, 1};
    assert(s.numRescueBoats(b, 3) == 3);

    // LeetCode example 3: nobody can share a boat
    std::vector<int> c{3, 5, 3, 4};
    assert(s.numRescueBoats(c, 5) == 4);

    // Single person
    std::vector<int> d{4};
    assert(s.numRescueBoats(d, 4) == 1);

    // Everyone weighs exactly the limit: one boat each
    std::vector<int> e{5, 5, 5};
    assert(s.numRescueBoats(e, 5) == 3);

    // Pairs that add up to exactly the limit still fit
    std::vector<int> f{1, 4, 2, 3};
    assert(s.numRescueBoats(f, 5) == 2);

    // Odd count: two pairs plus one person alone
    std::vector<int> g{1, 1, 1, 1, 1};
    assert(s.numRescueBoats(g, 2) == 3);

    // Heaviest can't pair with anyone, the rest pair up: (5), (1,4), (2,3)
    std::vector<int> h{5, 1, 4, 2, 3};
    assert(s.numRescueBoats(h, 5) == 3);

    // Greedy trap: pairing the two lightest (1,2) wastes them; best is (1,3), (2,2)
    std::vector<int> i{2, 2, 1, 3};
    assert(s.numRescueBoats(i, 4) == 2);

    std::cout << "Boats to Save People: all tests passed\n";
}
