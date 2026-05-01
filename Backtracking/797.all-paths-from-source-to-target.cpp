/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  int SOURCE;
  int TARGET;
  void backtrack(vector<vector<int>> &graph, int node,
                 vector<vector<int>> &result, vector<int> &currentPath) {
    if (node == TARGET) {
      result.push_back(currentPath);
      return;
    }
    for (int &nbr : graph[node]) {
      currentPath.push_back(nbr);
      backtrack(graph, nbr, result, currentPath);
      currentPath.pop_back();
    }
  }

public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    SOURCE = 0;
    TARGET = graph.size() - 1;

    vector<vector<int>> result = {};
    vector<int> currentPath = {0};
    backtrack(graph, SOURCE, result, currentPath);
    return result;
  }
};
// @lc code=end
