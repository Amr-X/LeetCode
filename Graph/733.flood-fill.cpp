/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
  vector<int> dir_i{-1, 0, 1, 0};
  vector<int> dir_j{0, 1, 0, -1};

  void dfs(vector<vector<int>>& image, int i, int j, int& color,
           int& original_color) {
    for (int k = 0; k < dir_i.size(); k++) {
      int nei_i = i + dir_i[k];
      int nei_j = j + dir_j[k];
      bool valid_i = (0 <= nei_i && nei_i < image.size());
      bool valid_j = (0 <= nei_j && nei_j < image[0].size());
      if (valid_i && valid_j && image[nei_i][nei_j] == original_color) {
        image[nei_i][nei_j] = color;
        dfs(image, nei_i, nei_j, color, original_color);
      }
    }
  }

 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int color) {
    // pixel (i,j) has 4 neighbors -> (i+1,j),(i-1,j),(i,j+1),(i,j-1)
    // Do Dfs on each the of them if it matches the original color

    int original_color = image[sr][sc];
    if (original_color == color) return image;
    image[sr][sc] = color;

    // Very Big Note: Doing the traversal on the neighbors while at the node
    // - Changing the neighbor before going to it will save the us the trouble
    // of the visited vector
    dfs(image, sr, sc, color, original_color);

    return image;
  }
};
// @lc code=end
