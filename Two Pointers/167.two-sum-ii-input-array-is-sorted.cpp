/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    // Input: numbers = [1,2,3,4], target = 3
    // Output: [1,2]

    // To Be Fair: I Look At First Line Solution Only
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Same Idea (As Two Sum I): Hash numbers with indicies(why?indicies) -> What The Problem What as output
        // But Here It's A Two Pointer Problem

        // Idea: It's Sorted! Meaning (Smallest - small ... 0 ... big - Biggest)
        // Try smallest and Biggest -> Bigger than target? then Go Left and take smaller than biggest
        // 1 + 4 = 5 -> Big -> take smaller than 4 -> 3 -> 1+3 and so on

        // It's like (small↑ + big↓)
        size_t start = 0;
        size_t end = numbers.size()-1;

        while(start <= end){
            int is_target = numbers[start] + numbers[end];

            if(is_target == target) return {(int)start+1,(int)end+1};

            else if(is_target > target){ end--; }
            else{ start++; }
        }
        return {}; // I Don't Know 
    }
};
// @lc code=end

