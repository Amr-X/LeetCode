/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*
key = sorted_string O(m*log n)
*/
class Solution {
public:
    // O(m * n) m: number of strs , n: characters of each
    // strs = ["eat","tea","tan","ate","nat","bat"] -> [["bat"],["nat","tan"],["ate","eat","tea"]]
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Here is what I know 
        // We can categorize strs based on a key that should be the same
        // If applied on "eat" and "ate" Like this
        // String Key -> "10001000000000000001000000" 26 character string
        unordered_map<string,vector<string>> map;
        const int ALPHABETS_NUMBER = 26; 
        for (const string &str : strs) // eat , tea
        {
            vector<int> charactersVector(ALPHABETS_NUMBER,0); // [0,0,0,0...] 26
            // Get The Key To Access The Map -> You Will Find a Vector There 
            for (const char &ch : str) // e , a , t -> 
            {
                charactersVector[ch - 'a']++; // 'e' - 'a' -> give you where 'e' represented here
            }
            // Once Done [1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0]
            string key;
            for (int i = 0; i < ALPHABETS_NUMBER; i++)
            {   
                // Test Case 123 Needs A Delimiter Between
                //key += to_string(charactersVector[i]); // "10001000000000000001000000"
                key += to_string(charactersVector[i]) + '#'; // e.g., "1#0#0#0#1#0#...#"
            }
            // Push "eat", "tea",... to Vector At That Location
            map[key].emplace_back(str);
            
        }
        // All We Need Is Append Our Vectors to One Vector
        vector<vector<string>> result;
        result.reserve(map.size());
        for (const auto &pair : map)
        {
            result.emplace_back(pair.second);
        }
        return result;
    }
};
// @lc code=end

