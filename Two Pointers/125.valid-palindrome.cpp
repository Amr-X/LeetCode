/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
#include<string>
#include<cctype>
using namespace std;
// Input: s = "Was it a car or a cat I saw?"
// Output: true
class Solution {
public:
    bool isPalindrome(string s) { // -> "", " ", "A" <- Palindrome
        // Two Pointers at start and end -> looking for alphabet only
    if(s.empty()) return true;

    size_t start_index = 0;
    size_t end_index = s.size()-1;
    while(start_index < end_index){  // Changed <= to <
        while(start_index < end_index && !std::isalnum(s[start_index])){ start_index++; }
        while(start_index < end_index && !std::isalnum(s[end_index])){ end_index--; }
            // while (l < r && !alphaNum(s[l])) {
            //     l++;
            // }
            // while (r > l && !alphaNum(s[r])) {  /// THINK ABOUT THIS IDIOT
            //     r--;
            // }
        if(start_index >= end_index) break;
        if (std::tolower(s[start_index]) != std::tolower(s[end_index])){ return false; }
        start_index++;
        end_index--;
    }       
    return true;
    }
};
// @lc code=end

