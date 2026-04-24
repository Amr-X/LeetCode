/*
 * @lc app=leetcode id=2059 lang=cpp
 *
 * [2059] Minimum Operations to Convert Number
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;

class Solution {
  vector<int> generate_neighbors(vector<int>& values, int num) {
    vector<int> result;
    result.reserve(values.size() * 3);
    for (auto& value : values) {
      result.push_back(num + value);
      result.push_back(num - value);
      result.push_back(num ^ value);
    }
    return result;
  }

 public:
  int minimumOperations(vector<int>& nums, int start, int goal) {
    // Graph Problems are implicit most of the time

    // I thought we don't need the visited for some reason
    // But think of [2,...] start = 0
    // 0 -> (+2) 2 --> (+2) 4
    // ====-> ................
    // 0 -> (-2)-2 --> (+2) 0 -> Repeat

    // Insted of set -> The constrain makes it possible
    vector<bool> visited(1001);

    queue<int> q;
    visited[start] = true;  // No need for this -> start != goal
    q.push(start);
    int lvl = 0;
    while (!q.empty()) {
      int sz = q.size();
      while (sz--) {
        int next_node = q.front();
        q.pop();
        vector<int> neighbors = generate_neighbors(nums, next_node);
        for (auto& neighbor : neighbors) {
          if (neighbor == goal) {
            return lvl + 1;
          }
          if (0 <= neighbor && neighbor <= 1000 && !visited[neighbor]) {
            visited[neighbor] = true;
            q.push(neighbor);
          }
        }
      }
      lvl++;
    }
    return -1;
  }
};
// @lc code=end
