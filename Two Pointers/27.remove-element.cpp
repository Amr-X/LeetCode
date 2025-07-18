/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
#include <vector>
using namespace std;
// Input: nums = [0,1,2,2,3,0,4,2], val = 2
// Output: 5, nums = [0,1,4,0,3,_,_,_]
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t idx{};
        for (size_t curr = 0; curr < nums.size(); curr++)
        {
            if(nums[curr] != val)
                nums[idx++] = nums[curr];
        }
        return idx;
        
    }
};
// @lc code=end

