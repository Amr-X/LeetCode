/*
 * @lc app=leetcode id=1905 lang=cpp
 *
 * [1905] Count Sub Islands
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
  void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j,
           vector<vector<bool>>& visited, bool& is_sub) {
    visited[i][j] = true;
    is_sub = (is_sub && grid1[i][j] == 1);
    for (int k = 0; k < dir_i.size(); k++) {
      int nei_i = i + dir_i[k];
      int nei_j = j + dir_j[k];
      if (not_valid(grid2, nei_i, nei_j)) continue;
      if (!visited[nei_i][nei_j] && grid2[nei_i][nei_j] == 1) {
        dfs(grid1, grid2, nei_i, nei_j, visited, is_sub);
      }
    }
  }
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    // What you take from this is how to do the is_sub variable
    // And to know that you must traverse the current connected component as a
    // whole and after it whether you found it's a sub-island or not
    int count = 0;
    vector<vector<bool>> visited(grid2.size(), vector<bool>(grid2[0].size()));
    for (int i = 0; i < grid2.size(); i++) {
      for (int j = 0; j < grid2[0].size(); j++) {
        if (!visited[i][j] && grid2[i][j] == 1) {
          bool is_sub = true;
          (dfs(grid1, grid2, i, j, visited, is_sub));
          if (is_sub) count++;
        }
      }
    }
    return count;
  }
};
// @lc code=end
