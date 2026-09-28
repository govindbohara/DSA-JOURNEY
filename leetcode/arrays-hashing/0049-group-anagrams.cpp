// 49. Group Anagrams (Medium)
// https://leetcode.com/problems/group-anagrams/
// Date:
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
#include <vector>

class Solution {
   public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;

        for (std::string s : strs) {
            int freq[26] = {0};
            std::string line = "";
            for (char c : s) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                line += std::to_string(freq[i]);
                if (i < 25) {
                    line += "#";
                }
            }
            map[line].push_back(s);
        }

        std::vector<std::vector<std::string>> res;
        for (auto& pair : map) {
            res.push_back(pair.second);
        }

        return res;
    }
};

// Anagram groups can come back in any order, so normalize both sides
// (sort each group, then sort the list of groups) before comparing.
static void normalize(std::vector<std::vector<std::string>>& groups) {
    for (auto& group : groups) std::sort(group.begin(), group.end());
    std::sort(groups.begin(), groups.end());
}

int main() {
    Solution s;

    std::vector<std::string> input{"eat", "tea", "tan", "ate", "nat", "bat"};
    auto result = s.groupAnagrams(input);
    normalize(result);

    std::vector<std::vector<std::string>> expected{{"ate", "eat", "tea"}, {"bat"}, {"nat", "tan"}};
    normalize(expected);

    assert(result == expected);

    std::vector<std::string> empty_str{""};
    auto result2 = s.groupAnagrams(empty_str);
    assert(result2.size() == 1 && result2[0].size() == 1 && result2[0][0] == "");

    std::vector<std::string> single{"a"};
    auto result3 = s.groupAnagrams(single);
    assert(result3.size() == 1 && result3[0][0] == "a");

    std::cout << "Group Anagrams: all tests passed\n";
}
