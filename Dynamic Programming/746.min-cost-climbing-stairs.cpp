/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  int minCostClimbingStairs(vector<int> &cost, int i, vector<int> &dp) {
    if (i >= (int)cost.size())
      return 0;

    int &result = dp[i];
    if (result != -1)
      return result;
    int oneStepPath = cost[i] + minCostClimbingStairs(cost, i + 1, dp);
    int twoStepPath = 0;          // if we can't twoStep then it's cost is 0
    if (i < (int)cost.size() - 1) // Not last
      twoStepPath = cost[i + 1] + minCostClimbingStairs(cost, i + 2, dp);
    result = min(oneStepPath, twoStepPath);
    return result;
  }

public:
  int minCostClimbingStairs(vector<int> &cost) {
    vector<int> dp(cost.size(), -1);
    return minCostClimbingStairs(cost, 0, dp);
  }
};
// @lc code=end
