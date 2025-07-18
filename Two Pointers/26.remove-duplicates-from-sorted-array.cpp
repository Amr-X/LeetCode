/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    // Input: nums = [0,0,1,1,1,2,2,3,3,4]
    // Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
    int removeDuplicates(vector<int>& nums) { // O(n)
        // First Two Pointer
        // Idea: Pointer a head of use telling if we looking at something different 
        // Other than what we are currently looking at
        if(nums.size() <= 1) return (int)nums.size();
        size_t follower{0};
        size_t current{1};
        size_t index{0};
        for (;follower < nums.size(); follower++,current++)
        {
            if(current >= nums.size() || nums[follower] != nums[current])
                nums[index++] = nums[follower];
            
        }
        return index;
        
    }
};
// @lc code=end

