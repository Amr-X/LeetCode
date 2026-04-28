/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid, int i, int j,
                               vector<vector<int>> &dp) {
    if (i >= obstacleGrid.size() || j >= obstacleGrid[i].size() ||
        obstacleGrid[i][j] == 1)
      return 0;

    if (i == obstacleGrid.size() - 1 && j == obstacleGrid[i].size() - 1)
      return 1;

    int &result = dp[i][j];
    if (result != -1)
      return result;

    int rightWays = uniquePathsWithObstacles(obstacleGrid, i, j + 1, dp);
    int downWays = uniquePathsWithObstacles(obstacleGrid, i + 1, j, dp);
    return result = rightWays + downWays;
  }

public:
  // State can repeat F(0,0) => F(1,0) , F(0,1)
  // F(1,0) => F(2,0), *F(1,1)*
  // F(0,1) => *F(1,1)*,F(0,2)
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    if (obstacleGrid.empty())
      return 0;
    vector<vector<int>> dp(obstacleGrid.size(),
                           vector<int>(obstacleGrid[0].size(), -1));
    return uniquePathsWithObstacles(obstacleGrid, 0, 0, dp);
  }
};
// @lc code=end
