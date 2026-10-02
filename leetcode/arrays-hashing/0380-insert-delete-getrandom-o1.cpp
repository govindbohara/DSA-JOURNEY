// 380. Insert Delete GetRandom O(1) (Medium)
// https://leetcode.com/problems/insert-delete-getrandom-o1/
// Date:       2026-10-02
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

// Every operation must run in average O(1) time.
class RandomizedSet {
   public:
    std::unordered_map<int, int> map;
    std::vector<int> output;
    RandomizedSet() {}

    bool insert(int val) {
        if (map.find(val) != map.end()) return false;
        output.push_back(val);
        map[val] = static_cast<int>(output.size()) - 1;
        return true;
    }

    bool remove(int val) {
        auto it = map.find(val);
        if (it == map.end()) return false;

        int removeIdx = it->second;
        int lastIdx = static_cast<int>(output.size()) - 1;
        int lastVal = output[lastIdx];

        // Move the last element into the removed position.
        output[removeIdx] = lastVal;
        map[lastVal] = removeIdx;

        output.pop_back();
        map.erase(val);

        if (removeIdx == lastIdx) {
            map.erase(lastVal);
        }
        return true;
    }

    int getRandom() { return output[rand() % output.size()]; }
};

int main() {
    // LeetCode example 1
    RandomizedSet rs;
    assert(rs.insert(1) == true);
    assert(rs.remove(2) == false);
    assert(rs.insert(2) == true);
    int r = rs.getRandom();
    assert(r == 1 || r == 2);
    assert(rs.remove(1) == true);
    assert(rs.insert(2) == false);
    assert(rs.getRandom() == 2);

    // Remove then re-insert the same value
    RandomizedSet b;
    assert(b.insert(5) == true);
    assert(b.remove(5) == true);
    assert(b.remove(5) == false);
    assert(b.insert(5) == true);
    assert(b.getRandom() == 5);

    // Removing from the middle must keep the rest reachable
    RandomizedSet c;
    for (int v : {10, 20, 30, 40}) assert(c.insert(v) == true);
    assert(c.remove(20) == true);
    std::unordered_set<int> seen;
    for (int i = 0; i < 1000; i++) seen.insert(c.getRandom());
    assert(seen == (std::unordered_set<int>{10, 30, 40}));

    std::cout << "Insert Delete GetRandom O(1): all tests passed\n";
}
