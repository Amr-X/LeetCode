/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  const int NOT_FOUND = INT_MIN;
  int minFallingPathSum(vector<vector<int>> &matrix, int i, int j,
                        vector<vector<int>> &dp) {
    int n = matrix.size();
    if (i >= n || i < 0 || j >= n || j < 0)
      return INT_MAX;
    if (i == n - 1)
      return matrix[i][j];
    int &result = dp[i][j];
    if (result != NOT_FOUND)
      return result;
    int path1 = minFallingPathSum(matrix, i + 1, j - 1, dp);
    int path2 = minFallingPathSum(matrix, i + 1, j, dp);
    int path3 = minFallingPathSum(matrix, i + 1, j + 1, dp);
    return result = matrix[i][j] + min(path1, min(path2, path3));
  }

public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    int n = (int)matrix.size();
    // I forgot negative numbers exist in this problem
    vector<vector<int>> dp(n, vector<int>(n, NOT_FOUND));
    int minPath = INT_MAX;
    for (int j = 0; j < n; j++) {
      minPath = min(minPath, minFallingPathSum(matrix, 0, j, dp));
    }
    return minPath;
  }
};
// @lc code=end
