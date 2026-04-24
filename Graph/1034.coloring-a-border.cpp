/*
 * @lc app=leetcode id=1034 lang=cpp
 *
 * [1034] Coloring A Border
 */

// @lc code=start
#include <list>
#include <vector>
using namespace std;

class Solution {
  vector<int> dir_i{-1, 0, 1, 0};
  vector<int> dir_j{0, 1, 0, -1};

  bool not_valid(vector<vector<int>>& grid, int i, int j) {
    return (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size());
  }

 public:
  void dfs(vector<vector<int>>& grid, int i, int j, int new_color,
           vector<vector<bool>>& visited, vector<pair<int, int>>& borders) {
    visited[i][j] = true;
    bool is_border = false;
    for (int k = 0; k < dir_i.size(); k++) {
      int nei_i = i + dir_i[k];
      int nei_j = j + dir_j[k];
      if (not_valid(grid, nei_i, nei_j) || grid[nei_i][nei_j] != grid[i][j]) {
        is_border = true;
        continue;
      }
      if (!visited[nei_i][nei_j]) {
        dfs(grid, nei_i, nei_j, new_color, visited, borders);
      }
    }
    if (is_border) borders.push_back({i, j});
  }

  vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col,
                                  int color) {
    // What You should know is that -> You are mutating the grid while
    // traversing this is what is causing all the problems
    // You change the color of a pixel that makes the inner pixels be a border
    // Long story short, Just use extra space and time first then refine your
    // logic if possible
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
    vector<pair<int, int>> borders;

    dfs(grid, row, col, color, visited, borders);

    for (auto& [i, j] : borders) grid[i][j] = color;

    return grid;
  }
};
// KILL ME
// Wrong Answer
// 150/155 cases passed (N/A)
// Testcase
// [[1,1,1],[1,1,1],[1,1,1]]
// 1
// 1
// 2
// Answer
// [[2,2,2],[2,2,2],[2,2,2]]
// Expected Answer
// [[2,2,2],[2,1,2],[2,2,2]]
// @lc code=end
