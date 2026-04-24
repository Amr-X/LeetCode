/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

// @lc code=start
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
  string add_one(string string, int index) {
    char value = (string[index] - '0') + 1;
    if (value >= 10) value = 0;
    string[index] = value + '0';
    return string;
  }
  string remove_one(string string, int index) {
    char value = (string[index] - '0') - 1;
    if (value <= 0) value = 9;
    string[index] = (value) + '0';
    return string;
  }

  vector<string> next_states(string& current_state) {
    // 0000 -> 1000,0100,..,9000,0900,0090,0009
    vector<string> result(8);
    for (int i = 0; i < 4; i++) {
      result.push_back(add_one(current_state, i));
      result.push_back(remove_one(current_state, i));
    }
    return result;
  }

 public:
  int openLock(vector<string>& deadends, string target) {
    // Nodes -> State of the lock
    // Edges -> Transition from a state in one single move

    // O(1) Look up
    unordered_set<string> is_deadend(deadends.begin(), deadends.end());

    queue<string> q;

    // Note: is_deadend and visited are the same -> Should be only one set here
    unordered_set<string> visited;

    string start = "0000";
    // Really? come on guys
    if (is_deadend.count(start)) return -1;
    if (start == target) return 0;

    visited.insert(start);
    q.push(start);

    int lvl = 0;
    while (!q.empty()) {
      int sz = q.size();
      while (sz--) {
        string curr = q.front();
        q.pop();
        vector<string> states = next_states(curr);
        for (auto& state : states) {
          if (!visited.count(state) && !is_deadend.count(state)) {
            visited.insert(state);
            if (state == target) {
              return lvl + 1;
            }
            q.push(state);
          }
        }
      }
      lvl++;
    }
    return -1;
  }
};
// @lc code=end
