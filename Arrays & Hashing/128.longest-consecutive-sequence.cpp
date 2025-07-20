/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    /*
    First Thought:
        - Radix Sort 
        Problems: negative integers - Bounding Max_int
    */

    // I Find Analysis Hard On This One <-----
    int longestConsecutive(vector<int>& nums) {
        // Store in set (map without values) - Why? fast lookups O(1)
        unordered_set<int> set{nums.begin(),nums.end()}; // Better - less lines - So REMEMBER   
        // NOTE: Set Stores Them Uniquely - So No Duplication Here
        int max{0};
        // Want to find 4 Easy -> hash -> index of where it is -> BOOM!
        for (auto &num : set) // You Can Iterate Here But -> Not The Order You Inserted Them <- It's HashMap
        {
            int n{num}; // 2
            int length{1};
            // To Not Waste Time - Check For (1) If exist means 2 is a waste of time since 1 will be get longer sequence
            if(set.find(n-1) == set.end()){ // Is The Previous Number(1) Not Here? Okay Go On..
                while(set.count(++n)){
                    // Found
                    length++;
                }
            }
            
            max = std::max<int>(max,length);
        }
        return max;
    }
    
};
// @lc code=end

