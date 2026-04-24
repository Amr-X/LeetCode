/*
 * @lc app=leetcode id=690 lang=cpp
 *
 * [690] Employee Importance
 */

// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 private:
  int DFS(unordered_map<int, Employee*>& map, int id) {
    int sum = map[id]->importance;
    for (auto& subordinate : map[id]->subordinates) {
      sum += DFS(map, subordinate);
    }
    return sum;
  }

 public:
  int getImportance(vector<Employee*> employees, int id) {
    // It's already a graph -> Just map the id to the employee
    unordered_map<int, Employee*> map;
    for (int i = 0; i < employees.size(); i++) {
      map[employees[i]->id] = employees[i];
    }

    return DFS(map, id);
  }
};
// @lc code=end
