/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
  vector<int> dir_i{-1, 0, 1, 0};
  vector<int> dir_j{0, 1, 0, -1};

  bool not_valid(vector<vector<int>>& grid, int i, int j) {
    return (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size());
  }

 public:
  void dfs(vector<vector<int>>& grid, int i, int j,
           vector<vector<bool>>& visited, bool& is_closed) {
    visited[i][j] = true;
    for (int k = 0; k < dir_i.size(); k++) {
      int nei_i = i + dir_i[k];
      int nei_j = j + dir_j[k];
      if (not_valid(grid, nei_i, nei_j)) {
        is_closed = false;
        continue;
      }
      if (!visited[nei_i][nei_j] && grid[nei_i][nei_j] == 0) {
        dfs(grid, nei_i, nei_j, visited, is_closed);
      }
    }
  }
  int closedIsland(vector<vector<int>>& grid) {
    // First I thought this hard to figure out how can I know if the 0's (that I
    // will traverse) Will be surrounded by 1's ??? But no think the other way
    // around The 0's are not surrounded if it's on the border (Note: Imagine
    // anything outside the grid is 0)
    int count = 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (!visited[i][j] && grid[i][j] == 0) {
          bool is_closed = true;
          dfs(grid, i, j, visited, is_closed);
          count += is_closed;
        }
      }
    }
    return count;
  }
};
// @lc code=end
