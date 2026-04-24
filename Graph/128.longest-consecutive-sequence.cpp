/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
  typedef unordered_map<int, vector<int>> Graph;

  int dfs(Graph& graph, int start, int& count, unordered_set<int>& visited) {
    visited.insert(start);
    for (auto& node : graph[start]) {
      // Directed and only one neighbor maximum
      if (!visited.count(node)) return 1 + dfs(graph, node, count, visited);
    }
    return 1;
  }

 public:
  // Noticed the diff between (2,3,4,5) as a group and (10,11,12) as other group
  // This is a connected component, That is how i know it's a graph problem

  // Think ->
  int longestConsecutive(vector<int>& nums) {
    // Note: Graph Reduction
    // Solved before -> Using a set -> O(n) Time is a constrain

    Graph graph;
    for (int x : nums) graph[x];  // Empty vectors

    for (auto& [node, neighbors] : graph) {
      if (graph.count(node + 1)) {
        neighbors.push_back(node + 1);
      }
    }

    // To avoid revisiting
    unordered_set<int> visited;
    int max = 0;
    for (auto& [node, neighbors] : graph) {
      if (!visited.count(node) && !graph.count(node - 1)) {
        // Start of the sequence -> I really can't think now - WHERE IS THE BED!
        int count = dfs(graph, node, count, visited);
        max = std::max(count, max);
      }
    }

    return max;
  }
};
// @lc code=end
