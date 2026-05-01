/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// 3H to solve
class Solution {
  bool canPlace(vector<vector<char>> &board, int i, int j, char k) {
    int n = board.size();

    // Right,Left and Up,Down
    for (int r = 0; r < n; r++) {
      if (board[r][j] == k)
        return false;
      if (board[i][r] == k)
        return false;
    }

    // current 3*3 - Hope it works
    for (int r = (i / 3) * 3, end_r = r + 3; r < end_r; r++) {
      for (int c = (j / 3) * 3, end_c = c + 3; c < end_c; c++) {
        if (board[r][c] == k)
          return false;
      }
    }
    return true;
  }
  bool solve(vector<vector<char>> &currentBoard, int i, int j) {
    // Solution found
    if (i >= currentBoard.size()) {
      /*
      I want to stop the recursive calls
      Instead of this =>    finalcurrentBoard = board;
      The pattern I found is to return bool to indicate that you found the
      solution -> You recurse and then check before the undo step. Did you solve
      it? you return true
      */
      return true;
    }
    // Row done
    if (j >= currentBoard[i].size()) {
      return solve(currentBoard, i + 1, 0);
    }
    // Occupied -> Go next cell
    if (currentBoard[i][j] != '.') {
      return solve(currentBoard, i, j + 1);
    }
    // Try all from 1 to 9
    for (char k = '1'; k <= '9'; k++) {
      // You can't place because the constrains of the game
      if (!canPlace(currentBoard, i, j, k))
        continue;

      currentBoard[i][j] = k; // Place
      if (solve(currentBoard, i, j + 1))
        return true; // returns true if solved -> We return true to tell other
                     // calls that it's solved
      currentBoard[i][j] = '.';
    }
    return false;
  }

public:
  void solveSudoku(vector<vector<char>> &board) {
    bool solved = solve(board, 0, 0);
    // True only
  }
};

// @lc code=end
