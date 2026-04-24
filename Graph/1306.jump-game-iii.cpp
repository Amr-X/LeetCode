/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;

using Graph = vector<vector<int>>;
class Solution {
  bool not_valid(int index, int range) { return index >= range || index < 0; }
  void connect_graph(Graph& graph, vector<int>& arr) {
    int n = graph.size();
    for (int node = 0; node < n; node++) {
      int value = arr[node];  // To jump to

      int right = node + value;  // Right
      if (!not_valid(right, n)) graph[node].push_back(right);

      int left = node - value;  // And Left
      if (!not_valid(left, n)) graph[node].push_back(left);
    }
  }
  bool bfs_is_exist(Graph& graph, int start, vector<int>& arr, int value) {
    int n = graph.size();
    vector<bool> visited(n);
    if (arr[start] == 0) return true;
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
      int sz = q.size();
      while (sz--) {
        int node = q.front();
        q.pop();
        for (auto& neighbor : graph[node]) {
          if (!visited[neighbor]) {
            visited[neighbor] = true;
            if (arr[neighbor] == 0)
              return true;  // <-- Found the index that has the value 0
            q.push(neighbor);
          }
        }
      }
    }
    return false;
  }

 public:
  // Note: First, Why Build the graph explicitly? Implicit Graph
  // This is Dump tbh -> Done in other questions - Learn from mistakes
  bool canReach(vector<int>& arr, int start) {
    // numbers are the node
    // Jumpable is edge
    // and just search for value 0;
    int n = arr.size();
    Graph graph(n);
    // Connecting the graph -> Jumpable edges
    connect_graph(graph, arr);
    // Bfs on value 0
    // Question: Do we need the visited logic here?
    // Yes, [1,1] will have a cycle, So Yesvector<bool> visited(n);
    return bfs_is_exist(graph, start, arr, 0);
  }
};
// @lc code=end
