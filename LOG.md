# Log

Newest first. Format: `date — minutes — what I did — what I didn't understand`

<!-- example:
2026-10-01 — 45 min — learncpp ch.1, Contains Duplicate (alone, 18 min) — why unordered_set instead of set?
-->

here the set was not used because how the data is maintained here the set maintains the value in BST for seaching and inserting would take logn time and here in unordered it takes constant time so it was used but i used map.

#2026-09-23 Wednesday Valid Anagram
Here first i used map and counted the characters and incremented the map and again looped in another string and checked if the charcter is in map and decremented the count and checked if not then not anagram if all charctaer passes then it is an anagram
and the second optimal approach because first solution was O(n) for space and second solution was done in O(1) using a freq array which used "c- 'a'" which is used to get a position and incremented and decrementing to know if its an anagram
