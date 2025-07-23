/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include<algorithm>
#include<vector>
using namespace std;
// It's Taking Some Time 1 Hour till now
class Solution {
public:
    // Input: nums = [-1,0,1,2,-1,-4]
    // Output: [[-1,-1,2],[-1,0,1]]

    // Duplication IS DRIVING ME CRAZY HELP
    // Took Last Part Of This Hint : o avoid duplicate triplets, skip the iterations where nums[i]==nums[i-1] 
    // and also skip the iterations where nums[j]==nums[j-1] or nums[k]==nums[k+1].
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Brute Force : O(n^3) For Every i For Every j For Every K - Not Sorted We Have To Look For ALl Again

        // Idea: Sort Them - And Do Like Two-Sum II

        sort(nums.begin(),nums.end()); // O(log n)
        // [-4,-1,-1,0,1,2]

        vector<vector<int>> result; // What Size To Predict?
        for (size_t i = 0; i < nums.size(); i++) // O(n)
        {
            size_t j = i+1;
            size_t k = nums.size()-1;
            if(i && nums[i] == nums[i-1] ){
                continue;
            }
            while(j < k){ // O(n/2)
                size_t is_target = nums[i] + nums[j] + nums[k];
                if(is_target == 0){
                    result.push_back({(int)nums[i],(int)nums[j],(int)nums[k]});
                    // Missing Element - Will Work if Difference is 1 <- I Don't Want To Explain it
                    while(j < k && nums[j] == nums[j+1]) j++;
                    while(j < k && nums[k] == nums[k-1]) k--;
                    k--;j++;
                }else if (is_target > 0){
                    k--;
                }else{
                    j++;
                }
            }
        }
        return result;
       // Time : O(log n) + O(n)*O(n/2) -> O(n^2) 
    }
};
// @lc code=end

