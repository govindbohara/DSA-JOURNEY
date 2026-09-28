// 242. Valid Anagram (Easy)
// https://leetcode.com/problems/valid-anagram/
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
#include <string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        // Your solution here.
        (void)s;
        (void)t;
        return false;
    }
};

int main() {
    Solution s;

    assert(s.isAnagram("anagram", "nagaram") == true);
    assert(s.isAnagram("rat", "car") == false);
    assert(s.isAnagram("a", "ab") == false);   // different lengths

    std::cout << "Valid Anagram: all tests passed\n";
}
