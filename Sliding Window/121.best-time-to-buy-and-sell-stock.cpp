/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include<vector>
using namespace std; // Input: prices = [7,1,5,3,6,4] // Output: 5
class Solution {
    // Time: Took Very Long Time And It's Very Simple - Took 1 hour 
    // Seen Solution For 
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0; // You can't profit from 1 day or 0 days
        size_t best_buy = 0;
        size_t best_sell = 1;
        size_t max_profit = 0;
        while(best_sell < prices.size()){
            if(prices[best_sell] > prices[best_buy]){
                size_t profit = prices[best_sell] - prices[best_buy]; // What we will profit
                max_profit = max(max_profit,profit);// Make sure it's greater than the max
            }else{
                // Better Day here to buy
                best_buy = best_sell;
            }
            best_sell++;
        }
        return max_profit;
    }
};
// @lc code=end

