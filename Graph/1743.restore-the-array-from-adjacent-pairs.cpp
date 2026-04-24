/*
 * @lc app=leetcode id=1743 lang=cpp
 *
 * [1743] Restore the Array From Adjacent Pairs
 */

// @lc code=start
#include <climits>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
  void dfs(unordered_map<int, vector<int>>& graph, int start,
           vector<int>& result, int parent_node = INT_MIN) {
    result.push_back(start);
    for (auto& neighbor : graph[start]) {
      // One is the parent, The other isn't
      // Could have used unordered_set<bool> visited -> But over kill in this
      // simple graph
      if (neighbor != parent_node) {
        dfs(graph, neighbor, result, start);
      }
    }
  }
  int find_start_node(unordered_map<int, vector<int>>& graph) {
    int start = INT_MIN;
    for (auto& [value, vec] : graph) {
      if (vec.size() == 1) {
        start = value;
        break;
      }
    }
    return start;
  }

 public:
  vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    // Note: Graph Reduction
    // Graph -> Node: value, Edge: Next to each other Undirected
    // if [a,b] means [a,b] or [b,a]
    unordered_map<int, vector<int>> graph;
    for (auto& adjacentPair : adjacentPairs) {
      graph[adjacentPair[0]].push_back(adjacentPair[1]);
      graph[adjacentPair[1]].push_back(adjacentPair[0]);
    }

    // Now it's a chain graph like 4-5-3-6
    // It's wrong to just start anywhere We need any of the starting point of
    // the graph like [4,6] above
    // We are now literally lost -> No start point -> Search for it o(n)
    int start = find_start_node(graph);

    vector<int> result;
    result.reserve(graph.size());
    // No need for visited - It's more like a recursive linked list
    // But don't forget to deal with the directed edges
    dfs(graph, start, result);
    return result;
  }
};
// @lc code=end
