/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
  int time = 0;

  bool DFS(vector<vector<int>>& graph, int curr_node, vector<bool>& visited,
           vector<int>& result, vector<bool>& finished) {
    visited[curr_node] = true;
    for (auto& nbr : graph[curr_node]) {
      if (!visited[nbr]) {
        if (DFS(graph, nbr, visited, result, finished)) return true;
      } else if (!finished[nbr]) {
        // This neighbor (already visited) and not done yet
        // Means it's on this Edge tree and it's one of the parents that called
        // us Looking at the past is called a back edge. Hence, A Cycle
        // Detection
        return true;
      }
    }
    // Here is the magic
    result.push_back(curr_node);
    finished[curr_node] = true;
    return false;
  }

 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    // Toposort using DFS
    vector<vector<int>> graph(numCourses);
    for (auto& pre : prerequisites) {
      graph[pre[1]].push_back(pre[0]);  // Directed -> Toposort
    }
    // Don't need the in_degree vector
    vector<bool> visited(numCourses, false);
    vector<bool> finished(numCourses, false);
    vector<int> result;
    for (int i = 0; i < graph.size(); i++) {
      if (!visited[i]) {
        bool is_cycle = DFS(graph, i, visited, result, finished);
        if (is_cycle) return vector<int>();  // A Loop
      }
    }
    // Dfs Gets the reverse of toposort
    reverse(result.begin(), result.end());
    return result;
  }
};
// @lc code=end
