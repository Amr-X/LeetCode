/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  // Get all the valid combination
  // How to split "12"? It's F(12) = 1,F(2) - 12 F(-)
  // F(226) = 2,F(26) - 22,F(6) - 226,F(-) <- Wrong! Only in range of 1 to 26
  // F(06) = 0,F(6) <- Wrong! Again Only in range of 1 to 26

  int numDecodings(string s, int i, vector<int> &dp) {
    if (i >= s.size())
      return 1; // One successful decode

    int &result = dp[i];
    if (result != -1)
      return result;

    int sum = 0;
    // Single digit: valid if not '0'
    if (s[i] != '0') {
      sum += numDecodings(s, i + 1, dp);
      // Two digits: valid if 10-26
      if (i + 1 < s.size()) {
        int twoDigit = stoi(s.substr(i, 2));
        if (twoDigit <= 26) {
          sum += numDecodings(s, i + 2, dp);
        }
      }
    }
    return result = sum;
  }

public:
  // 2226 Can have a repeating call
  // 2 F(226) -> F(226) = 2 *F(26)*
  // 22 *F(26)*
  int numDecodings(string s) {
    vector<int> dp(s.size(), -1);
    return numDecodings(s, 0, dp);
  }
};
// @lc code=end
