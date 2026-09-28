// 217. Contains Duplicate (Easy)
// https://leetcode.com/problems/contains-duplicate/
// Date:
// Result:     alone | hint | read solution
// Time taken: __ min
//
// Approach, in two lines of my own words:
//
//
// Complexity: time O(?), space O(?)
// C++ I learned:

#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        // Your solution here. Hint only if stuck past 20 minutes:
        // what data structure answers "have I seen this before?" in O(1)?
        (void)nums;
        return false;
    }
};

int main() {
    Solution s;

    std::vector<int> a{1, 2, 3, 1};
    std::vector<int> b{1, 2, 3, 4};
    std::vector<int> c{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    std::vector<int> single{7};

    assert(s.containsDuplicate(a) == true);
    assert(s.containsDuplicate(b) == false);
    assert(s.containsDuplicate(c) == true);
    assert(s.containsDuplicate(single) == false);

    std::cout << "Contains Duplicate: all tests passed\n";
}
