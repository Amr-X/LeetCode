/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool isUnderAttack(vector<string> &chessboard, int i, int j) {
    int n = chessboard.size();
    // column
    for (int k = 0; k < n; k++)
      if (chessboard[k][j] == 'Q')
        return true;

    // top-left
    for (int r = i - 1, c = j - 1; r >= 0 && c >= 0; r--, c--)
      if (chessboard[r][c] == 'Q')
        return true;

    // top-right
    for (int r = i - 1, c = j + 1; r >= 0 && c < n; r--, c++)
      if (chessboard[r][c] == 'Q')
        return true;
    return false;
  }
  void backtrack(vector<string> &chessboard, int i,
                 vector<vector<string>> &result) {
    // if we reached outside of the rows then we have put all the queens - We
    // just save the current Configuration of the board
    if (i >= chessboard.size()) {
      result.push_back(chessboard);
      return;
    }

    for (int k = 0; k < chessboard.size();
         k++) { // For each cell in current Row
      if (isUnderAttack(chessboard, i, k)) {
        continue;
      }
      chessboard[i][k] = 'Q';
      backtrack(chessboard, i + 1, result); // Next Row
      chessboard[i][k] = '.';
    }
  }

public:
  vector<vector<string>> solveNQueens(int n) {
    vector<string> chessboard(n, string(n, '.'));
    vector<vector<string>> result;
    backtrack(chessboard, 0, result);
    return result;
  }
};
// @lc code=end
