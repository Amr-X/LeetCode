/*
 * @lc app=leetcode id=1559 lang=cpp
 *
 * [1559] Detect Cycles in 2D Grid
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
  vector<int> dir_i{-1, 0, 1, 0};
  vector<int> dir_j{0, 1, 0, -1};

  bool not_valid(vector<vector<char>>& grid, int i, int j) {
    return (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size());
  }
  bool dfs_is_cycle(vector<vector<char>>& grid, int i, int j, int p_i, int p_j,
                    vector<vector<bool>>& visited) {
    visited[i][j] = true;
    for (int k = 0; k < dir_i.size(); k++) {
      int nei_i = i + dir_i[k];
      int nei_j = j + dir_j[k];
      if (not_valid(grid, nei_i, nei_j) || grid[nei_i][nei_j] != grid[i][j])
        continue;
      if (!visited[nei_i][nei_j]) {
        if (dfs_is_cycle(grid, nei_i, nei_j, i, j, visited)) return true;
      } else {
        // Think -> it's an already visited node which means it has the same
        // value Which means it's a cycle If it's parent (who called us) it's
        // not a cycle Otherwise it is
        if (nei_i != p_i || nei_j != p_j) {
          return true;
        }
      }
    }
    return false;
  }

 public:
  bool containsCycle(vector<vector<char>>& grid) {
    // Very interesting Solution
    // Use if encounter an already visited node then it's a cycle
    // except the partent node
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (!visited[i][j]) {
          if (dfs_is_cycle(grid, i, j, -1, -1, visited)) return true;
        }
      }
    }
    return false;
  }
};
// @lc code=end
