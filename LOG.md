# Log

Newest first. Format: `date — minutes — what I did — what I didn't understand`

<!-- example:
2026-10-01 — 45 min — learncpp ch.1, Contains Duplicate (alone, 18 min) — why unordered_set instead of set?
-->

here the set was not used because how the data is maintained here the set maintains the value in BST for seaching and inserting would take logn time and here in unordered it takes constant time so it was used but i used map.

#2026-09-23 Wednesday Valid Anagram
Here first i used map and counted the characters and incremented the map and again looped in another string and checked if the charcter is in map and decremented the count and checked if not then not anagram if all charctaer passes then it is an anagram
and the second optimal approach because first solution was O(n) for space and second solution was done in O(1) using a freq array which used "c- 'a'" which is used to get a position and incremented and decrementing to know if its an anagram

#2026-09-23 Wednesday Group Anagram
the approach i used was using unordered_map to track the corresponding anagram words and first i iterated over the vector of strings and made a freq vector to count the characters and converted them to string and stored it in a map and initialized the key
with the word as the value and checked for another words and if the key exists then pushed into the array using push_back method and lastly iterated over the map and added to the result variable.

##Thing i learnt
int freq[26] = {0}; initializing the empty array with 0;
std::to_string(freq[i]) converting int to string
auto& pair: map -- here auto is type auto and & is the value arent copied deeply only referenced so efficient and iterated over map
push_back(): it adds the item at last in the vector

2026-09-28 — 95 min — learncpp ch.4 finished incl. summary quiz; Majority Element (27 min, 1 hint, Boyer-Moore); revisits: Valid Sudoku (13 min, clean after 3 hints last time), Product of Array Except Self (4 min, read) — Sort Colors still to do. Stuck on: recalling prefix/suffix but not being able to write it unaided.
