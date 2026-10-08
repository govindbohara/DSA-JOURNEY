// 735. Asteroid Collision (Medium)
// https://leetcode.com/problems/asteroid-collision/
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
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "lc.hpp"

class Solution {
   public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::stack<int> st;

        for (int n : asteroids) {
            if (n > 0) {
                st.push(n);
                continue;
            }

            while (!st.empty() && st.top() > 0 && st.top() < std::abs(n)) {
                st.pop();
            }

            if (st.empty() || st.top() < 0) {
                st.push(n);
            }

            else if (st.top() == std::abs(n)) {
                st.pop();
            }
        }
        std::vector<int> res(st.size());
        for (int i = res.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};

int main() {
    Solution s;
    std::vector<int> a;

    // LeetCode example 1: 10 destroys -5
    a = {5, 10, -5};
    assert(s.asteroidCollision(a) == std::vector<int>({5, 10}));

    // LeetCode example 2: equal size, both explode
    a = {8, -8};
    assert(s.asteroidCollision(a) == std::vector<int>({}));

    // LeetCode example 3: -5 destroys 2, then 10 destroys -5
    a = {10, 2, -5};
    assert(s.asteroidCollision(a) == std::vector<int>({10}));

    // LeetCode example 4: -6 wipes out 3 and 5, then 2 and 4 survive -1
    a = {3, 5, -6, 2, -1, 4};
    assert(s.asteroidCollision(a) == std::vector<int>({-6, 2, 4}));

    // Moving apart: left ones go left, right ones go right, nothing collides
    a = {-2, -1, 1, 2};
    assert(s.asteroidCollision(a) == std::vector<int>({-2, -1, 1, 2}));

    // Single asteroid
    a = {-5};
    assert(s.asteroidCollision(a) == std::vector<int>({-5}));

    // One big left-mover destroys a whole chain
    a = {1, 2, 3, -10};
    assert(s.asteroidCollision(a) == std::vector<int>({-10}));

    // One big right-mover destroys every left-mover after it
    a = {10, -1, -2, -3};
    assert(s.asteroidCollision(a) == std::vector<int>({10}));

    // Pair explodes, then the rest have nothing to hit
    a = {1, -1, -2, -2};
    assert(s.asteroidCollision(a) == std::vector<int>({-2, -2}));

    // 2 survives -1, then dies together with -2
    a = {-2, 2, -1, -2};
    assert(s.asteroidCollision(a) == std::vector<int>({-2}));

    std::cout << "Asteroid Collision: all tests passed\n";
}
