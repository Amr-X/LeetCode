/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    // s = "anagram", t = "nagaram" -> True
    bool isAnagram(string s, string t) {
        // That was easy in a scary way
        if (s.length() != t.length()) return false; // Ofc They Will Not Ever Be ("Amr","Amro"),("Amr","Am")
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
    // Or HashMap {character1:frequency1} == {character2:frequency2}
};
// @lc code=end

