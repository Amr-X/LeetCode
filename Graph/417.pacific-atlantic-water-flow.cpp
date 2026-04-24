/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;

class Solution {
  vector<int> dir_i{-1, 0, 1, 0};
  vector<int> dir_j{0, 1, 0, -1};

  struct position {
    int i;
    int j;
  };
  bool not_valid(position p, vector<vector<int>>& grid) {
    return p.i < 0 || p.i >= grid.size() || p.j < 0 || p.j >= grid[0].size();
  }
  void BFS(vector<vector<int>>& heights, vector<position>& boundaries,
           vector<vector<bool>>& is_ocean) {
    queue<position> q;
    for (auto& boundary : boundaries) {
      is_ocean[boundary.i][boundary.j] = true;
      q.push(boundary);
    }

    while (!q.empty()) {
      int sz = q.size();
      while (sz--) {
        position curr = q.front();
        q.pop();
        for (int i = 0; i < dir_i.size(); i++) {
          position nbr = {curr.i + dir_i[i], curr.j + dir_j[i]};
          if (not_valid(nbr, heights) || is_ocean[nbr.i][nbr.j] ||
              heights[nbr.i][nbr.j] < heights[curr.i][curr.j]) {
            // All of this is invalid
            continue;
          }
          is_ocean[nbr.i][nbr.j] = true;
          q.push(nbr);
        }
      }
    }
  }

 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    // I know it's MultiSource Bfs
    // But I was missing the goal to start of
    // I thought that the goal was the ocean (invalid index)
    // But, It's the boundary of grid (Any of the boundary can reach that ocean
    // next to it)
    int n = heights.size();
    int m = heights[0].size();

    // Bfs from atlantic (right-bottom)
    // Searching the nodes that can reach the atlantic
    vector<vector<bool>> is_atlantic(n, vector<bool>(m));
    vector<position> atlantic_boundaries;
    for (int i = 0; i < n; i++) {
      atlantic_boundaries.push_back({i, m - 1});
    }
    for (int j = 0; j < m; j++) {
      atlantic_boundaries.push_back({n - 1, j});
    }
    BFS(heights, atlantic_boundaries, is_atlantic);

    // Bfs from Pacific (left-up)
    // Searching the nodes that can reach the Pacific
    vector<vector<bool>> is_pacific(n, vector<bool>(m));
    vector<position> pacific_boundaries;
    for (int i = 0; i < n; i++) {
      pacific_boundaries.push_back({i, 0});
    }
    for (int j = 0; j < m; j++) {
      pacific_boundaries.push_back({0, j});
    }
    BFS(heights, pacific_boundaries, is_pacific);
    //
    vector<vector<int>> result;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (is_atlantic[i][j] && is_pacific[i][j]) result.push_back({i, j});
      }
    }
    return result;
  }
};
// @lc code=end
