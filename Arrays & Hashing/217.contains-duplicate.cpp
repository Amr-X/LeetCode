/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;

// nums = [1,2,3,1] -> True 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> map;
        for (int &number : nums)
        {
            if(map.find(number) == map.end()){
                map[number] = true; // Doesn't Exist , Add it
            }else{
                return true; // Found an Already Stored Number (Duplicate)
            }
        } 
        return false;  
    }
};
// @lc code=end

