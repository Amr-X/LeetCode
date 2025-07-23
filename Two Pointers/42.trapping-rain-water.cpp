/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include<vector>
using namespace std;
// First Hard Problem
// 3 Hours
class Solution {
public:
    
    int trap(vector<int>& height) {
        // Big Failure
        size_t i = 0;
        size_t j = height.size() - 1;
        size_t water_level = 0;
        size_t width = 1;
        size_t space = 0;

        // First: Ignore Edges Only Between bars
        while(height[i] == 0){ i++; } // Here
        while(height[j] == 0){ j--; }
        size_t current = i+1;

        water_level = min(height[i],height[j]); 
        space = (water_level * (j-i-width));


        while(current < j){
            if(height[current] > water_level){  // Very Long Bar
                space =- (water_level * width); // Space Bar Takes
                if()
               // We have to know which bar is higher - Right or Left?
               // Why? 
               size_t longer_bar{};
               if(height[i] < height[j]){ // Right
                longer_bar = j;
               }else{ // Left or Equal
                longer_bar = i;
               } 
               space += (min(height[longer_bar],height[current]) - water_level) * (longer_bar-i-width);
            }else{
                space =- (height[current] * width); // Space Bar Takes
            }

            // Update Water level
            // water_level = height[current];
            current++;
        }
        return (int)space;

    }
};
// @lc code=end

