/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;
class Solution {
  using Graph = vector<vector<int>>;

 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // Topological Sort
    // Get the in-degree of each node
    // Start by the in-degree(0)
    // add it's neighbors and
    // The Graph
    Graph graph(numCourses);

    // This is the idea here
    vector<int> in_degree(numCourses);

    // Build the graph and in_degree of each
    for (auto& edge : prerequisites) {
      // Course depend on itself?
      if (edge[1] == edge[0]) {
        return false;
      }
      graph[edge[1]].push_back(edge[0]);
      in_degree[edge[0]]++;
    }
    int node_count = 0;
    queue<int> q;
    // Start by the in_degree of 0
    for (int node = 0; node < graph.size(); node++) {
      if (in_degree[node] == 0) {
        node_count++;
        q.push(node);
      }
    }
    // No Starting Point? Can't start a course that depend on a course that
    // depend on the first course
    if (q.empty()) return false;

    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      for (auto& nbr : graph[curr]) {
        if (--in_degree[nbr] == 0){
            node_count++;
            q.push(nbr);
        } 
      }
    }
    return node_count >= numCourses;
    // The idea of finding the cycle
    // if we stoped somewhere early (we didn't process all nodes)
    // Then we hit a point where a node can't push a nbr that has in-degree > 0
    // Think of a course(4) - you finish it you go to the next - you find you need one more course(3) (*1* after --2)
    // But you can't take this other course(3) because you can't can't go advance after finishing the first course(4)
    // *0*     *2*          *1*   *1*
    // (4) |-> (3) ------->(1) -> (0)
    //          ^           | 
    //          |           |
    //          (5) <- (6) <\
    //          *1*    *1*
  }
};
// @lc code=end
