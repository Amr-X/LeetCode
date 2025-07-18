/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Input: nums = [1,2,2,3,3,3], k = 2
    // Output: [2,3] - 2 Most Frequent Elements

    static vector<int> topKFrequent(vector<int>& nums, int k) {
        // Wil Be Back Here................
        unordered_map<int,int> frequency_map;
        // Loop On nums
        for (int number : nums) // 1 , 2 , ...
        {
            frequency_map[number]++;
        }
        // Everything Is Stored in The Map But We Need Most Frequent Of Them
        // Take In Array And Sort - You Need Both First and Second {value,frequency}
        vector<pair<int,int>> vec;
        vec.reserve(frequency_map.size());
        for (const auto &frequency_map_pair : frequency_map)
        {
            vec.emplace_back(frequency_map_pair.first,frequency_map_pair.second);
        }
        // Sort Based on frequency
        sort(vec.rbegin(),vec.rend()); // But Greatest First
        // {3,3},{2,2},{1,1}
        vector<int> res;
        res.reserve(k);
        for (size_t i = 0; i < k; i++)
        {
            res.push_back(vec[i].second);
        }
        
        
        return res;
        
    }
};

// int main(){
//     vector <int> vec = {1,2,2,3,3,3,0,0,0,0,0,0,0,0};
//     Solution::topKFrequent(vec,2);
// }
// @lc code=end

