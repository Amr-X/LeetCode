/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    // nums = [2,7,11,15], target = 9

    // Solution #1: O(n^2)  Try Every Pair

    // Solution #2: O(n) HashMap
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;

        for(int i = 0; i < nums.size(); i++){
            int diff = target - nums[i]; // 9 - 2 = 7 What we Look for
            auto it = map.find(diff); // In The Hash? O(1) Look up
            if(it == map.end()) // No?
                map[nums[i]] = i; // Add it {2:0} {element:index}
            else{
                return {i,it->second};   // Return index and element's index
            }
        }
        return {}; // If Can't Equal To Target
    }
};
// @lc code=end

