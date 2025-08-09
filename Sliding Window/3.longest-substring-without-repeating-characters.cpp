/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;

// Input: s = "zxyzxyz"
// Output: 3

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Idea: start at first letter "z" go check if we got any duplicates (set O(1) check)
        // once found start at new character after position of the duplicated character
        // Maintaining a maxCount 
        if(s.size() <= 1) return s.size();
        size_t i{0};
        size_t j{1};
        unordered_map<char,size_t> seen;
        seen[s[0]] = 0;
        size_t count{1};
        size_t current_count{1};
        while(j < s.size()){
            if(seen.count(s[j])){
               count = max(count,current_count);
               size_t to_start = seen[s[j]];
               seen.erase(s[j]); 
               i = to_start+1;
               current_count = j - i;
               count = max(count,current_count);
            }else{
                seen[s[j]] = j;
                current_count++;
                j++;
            }
        }
        return (int)max(count,current_count);

    }
};
// @lc code=end

