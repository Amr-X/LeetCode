/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        size_t low{0};
        size_t high{nums.size()-1};
        
        while(high > low){ 
            size_t mid{(low+high)/2}; 
            if(nums[mid] == target)
                return mid;
            else if(target > nums[mid]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        // One of Two 
        // 1# We are at the target
        // 2# Or This should be location if target doesn't exist
        size_t mid{(low+high)/2};
        if (nums[mid] == target)
            return mid;

        return (target > nums[mid])? mid+1:mid;

        
    }
};
// @lc code=end

