// 347. Top K Frequent Elements (Medium)
// https://leetcode.com/problems/top-k-frequent-elements/
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
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // Your solution here. Any order is accepted.
        std::unordered_map<int, int> map{};
        std::vector<int> res;
        for (int n : nums) {
            if (map.find(n) != map.end()) {
                map[n] += 1;
            } else {
                map[n] = 1;
            }
        }

        std::vector<std::vector<int>> buckets(nums.size() + 1);

        for (auto& pair : map) {
            buckets[pair.second].push_back(pair.first);
        }

        for (int i = nums.size(); i >= 0; i--) {
            if (buckets[i].empty()) {
                continue;
            }

            for (int v : buckets[i]) {
                res.push_back(v);
                if (res.size() == k) return res;
            }
        }

        return res;
    }
};

// LeetCode accepts the answer in any order, so sort before comparing.
std::vector<int> sorted(std::vector<int> v) {
    std::sort(v.begin(), v.end());
    return v;
}

int main() {
    Solution s;

    // LeetCode example 1
    std::vector<int> a{1, 1, 1, 2, 2, 3};
    assert(sorted(s.topKFrequent(a, 2)) == (std::vector<int>{1, 2}));

    // LeetCode example 2: single element
    std::vector<int> b{1};
    assert(sorted(s.topKFrequent(b, 1)) == (std::vector<int>{1}));

    // LeetCode example 3: elements not grouped together
    std::vector<int> c{1, 2, 1, 2, 1, 2, 3, 1, 3, 2};
    assert(sorted(s.topKFrequent(c, 2)) == (std::vector<int>{1, 2}));

    // Negative numbers
    std::vector<int> d{4, 1, -1, 2, -1, 2, 3};
    assert(sorted(s.topKFrequent(d, 2)) == (std::vector<int>{-1, 2}));

    // k equals the number of distinct elements
    std::vector<int> e{5, 5, 6, 6, 6, 7};
    assert(sorted(s.topKFrequent(e, 3)) == (std::vector<int>{5, 6, 7}));

    // Zero is a valid value
    std::vector<int> f{3, 0, 1, 0};
    assert(sorted(s.topKFrequent(f, 1)) == (std::vector<int>{0}));

    std::cout << "Top K Frequent Elements: all tests passed\n";
}
