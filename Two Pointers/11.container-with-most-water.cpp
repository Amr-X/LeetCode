/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include<vector>
using namespace std;

// Hint Used : One pointer is at the start and the other at the end. At each step
class Solution {
public:
    // Input: height = [1,7,2,5,4,7,3,6]
    // Output: 36
    int maxArea(vector<int>& height) {
        // This has to be the bigger volume - Since they are far apart
        size_t i = 0;
        size_t j = height.size() - 1;
        size_t max_volume{};
        
        while(i < j){
            // v = width * minimum one of the two heights
            size_t volume = (j - i) * min(height[i],height[j]);

            // Which is the lower bar?
            if(height[i] < height[j]) i++; // Left?  Go Right Get a higher one
            else                      j--; // Right? Go Left Get a Higher One

            // Note: You can smaller bar but the volume would would be less which we (yes) calculate 
            // but we ignore since it's not the max 

            // Store Max I Find
            max_volume = max(max_volume,volume);
        }
        return max_volume;
    }
};
// @lc code=end

