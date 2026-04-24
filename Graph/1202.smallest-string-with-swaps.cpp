/*
 * @lc app=leetcode id=1202 lang=cpp
 *
 * [1202] Smallest String With Swaps
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
  typedef vector<vector<int>> Graph;
  void dfs(Graph& graph, int start, vector<bool>& visited,
           vector<int>& result) {
    visited[start] = true;
    result.push_back(start);
    for (auto& node : graph[start]) {
      if (!visited[node]) {
        dfs(graph, node, visited, result);
      }
    }
  }

  void add_directed(Graph& graph, vector<int>& pair) {
    graph[pair[0]].push_back(pair[1]);
    graph[pair[1]].push_back(pair[0]);
  }

 public:
  //  if index a can swap with b, and b can swap with c, then a, b, and c are
  //  all connected and their characters can be freely rearranged among these
  //  positions.
  string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    // Note: Graph Reduction
    // Took the hint -> Sort each connected component
    int n = s.size();

    Graph graph(n);
    for (auto& pair : pairs) {
      add_directed(graph, pair);
    }

    vector<bool> visited(n);
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        // The connected indices [2,4,1,5] These are connected
        vector<int> indices;
        dfs(graph, i, visited, indices);
        // Corresponding characters s[i] = [z,b,a,f]
        string co_characters;
        for (auto& i : indices) co_characters += s[i];

        sort(indices.begin(), indices.end());
        sort(co_characters.begin(), co_characters.end());
        //[1,2,4,5]
        //[a,b,f,z]
        for (int i = 0; i < indices.size(); i++) {
          s[indices[i]] = co_characters[i];
        }
      }
    }
    return s;
  }
};
// @lc code=end
