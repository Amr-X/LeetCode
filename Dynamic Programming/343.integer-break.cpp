/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  // Simply We are trying every combinations that it's sum == n
  // 3 => 1+1+1, 1+2, 2+1(2+1)
  // n => i(1..n) + F(n-i)
  // Recursive problem that is overlapping F(n) => F(1) .. F(n) and again for
  // each one Add Memory to store them => You have DP
  int integerBreak(int n, vector<int> &dp) {
    if (n <= 2)
      return 1; // f(2) => 1 (1+1 - 1*1 = 1)

    int &result = dp[n];
    if (result == -1) {

      int maxProduct = 1;
      for (int i = 1; i < n; i++) {
        // if i <= n we call integerBreak(0) = 1 -> i = n -> we get n * 1 = n
        // F(n) can't be n we must break down the integer ex. f(3) != 3 you
        // can't say break it to 3 + 0 -> f(0) this is wrong So we max on both
        // i*F(n-i) and i * (n-i)
        maxProduct =
            max(i * integerBreak(n - i, dp), max(i * (n - i), maxProduct));
      }
      result = maxProduct;
    }
    return result;
  }

  // What is the Tabulation Version?
  int integerBreak(int num, int v) {
    if (num < 2)
      return 0;

    // We should fill the array from the subproblems to the problem
    vector<int> dp(num + 1);
    dp[0] = 1; // When we are at i * dp[0] the return value should equal to n (i
               // == n in this case) so yeah n * 1 = n
    dp[1] = 1, dp[2] = 1;
    // F(n) = Max(Σ(i) from i=1 to n * F(n-i))
    for (int n = 3; n < (int)dp.size(); n++) {
      for (int i = 1; i <= n; i++) {
        dp[n] = max(i * dp[n - i], max(i * (n - i), dp[n]));
      }
    }
    return dp.back();
  }

public:
  int integerBreak(int n) {
    vector<int> dp(n + 1, -1);
    return integerBreak(n, dp);
  }
};
