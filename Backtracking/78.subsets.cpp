/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
  vector<vector<int>> result;
  vector<int> currentPath;

  void subsetsHelper(vector<int> &nums, int i) {
    result.push_back(currentPath); // Save state here

    // The Possible Actions that we can do are from i+1 to n-1
    for (int j = i + 1; j < nums.size(); j++) {
      currentPath.push_back(nums[j]); // Update
      subsetsHelper(nums, j);         // Recurse
      currentPath.pop_back();         // Restore
    }
  }

public:
  vector<vector<int>> subsets(vector<int> &nums) {
    result = {};
    currentPath = {};
    subsetsHelper(nums, -1); // Note: -1
    return result;
  }
};

// @lc code=end
