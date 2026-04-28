/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  using Vector3D = vector<vector<vector<int>>>;
  using Vector2D = vector<vector<int>>;
  using Vector = vector<int>;
  using ll = long long;
  const int MOD = 1'000'000'007;

  // I Think this is 3D Dp state
  // First time solving 3D Dp
  int findPaths(int &m, int &n, int movesAllowed, int i, int j, Vector3D &dp) {
    if (i < 0 || i >= m || j < 0 || j >= n) { // Out of the boundary
      // that is one way if we have no moves left
      return movesAllowed <= 0;
    }
    // In Boundary but can't move anymore
    if (movesAllowed <= 0)
      return 0;

    int &result = dp[i][j][movesAllowed];
    if (result != -1)
      return result;
    // This is a nightmare to trace
    int right = findPaths(m, n, movesAllowed - 1, i, j + 1, dp);
    int down = findPaths(m, n, movesAllowed - 1, i + 1, j, dp);
    int left = findPaths(m, n, movesAllowed - 1, i, j - 1, dp);
    int up = findPaths(m, n, movesAllowed - 1, i - 1, j, dp);

    return result = ((ll)right + up + down + left) % MOD;
  }

public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    Vector3D dp(m, Vector2D(n, Vector(maxMove + 1, -1)));
    // It solves only maxMove times case
    // We need all cases from maxMoves to 1
    // I WAS RIGHT FUCK YOU GPT
    ll allPaths = 0;
    for (int currentMoves = maxMove; currentMoves >= 1; currentMoves--) {
      allPaths = (allPaths +
                  findPaths(m, n, currentMoves, startRow, startColumn, dp)) %
                 MOD;
    }
    return (int)allPaths;
  }
};
// @lc code=end
