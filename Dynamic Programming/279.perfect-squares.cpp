/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  int numSquares(int n, vector<int> &dp) {
    if (n <= 1)
      return n;
    int &result = dp[n];
    if (result != -1)
      return result;
    int minAnswer = INT_MAX;
    for (int i = 1; i * i <= n; i++) {
      int perfectNum = i * i;
      minAnswer = min(minAnswer, 1 + numSquares(n - perfectNum, dp));
    }
    return result = minAnswer;
  }

public:
  // Idea: is similar to integer break
  // We break n using this F(n) = i(1..n-1) + F(n-i)
  // We don't have to call each number from 1 to n-1
  // Just the prefect ones 1,4,9,16,...
  int numSquares(int n) {
    vector<int> dp(n + 1, -1);
    return numSquares(n, dp);
  }
};

// @lc code=end
