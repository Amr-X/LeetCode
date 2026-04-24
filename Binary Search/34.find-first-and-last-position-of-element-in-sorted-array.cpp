/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 private:
  /*              My Original Solution               */

  // Time O(n) <- [8,8,8,8,8,8,8,8,8]
  vector<int> searchRange1(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    int m = -1;
    bool found = 0;
    while (r >= l) {
      m = l + (r - l) / 2;  // avoid overflow for big ranges
      if (nums[m] == target) {
        found = 1;
        break;
      } else if (nums[m] < target)
        l = m + 1;
      else
        r = m - 1;
    }
    // Not found
    if (!found) return {-1, -1};
    // Getting the range
    int first = m, last = m;
    while (last + 1 < nums.size() && nums[last + 1] == target) last++;
    while (first - 1 >= 0 && nums[first - 1] == target) first--;
    return {first, last};
  }

  // Simple as if Found Continue and search for the left part for any number
  // less target
  int searchFirst(vector<int>& nums, int& target) {
    if (nums.empty()) return -1;
    int l = 0;
    int r = nums.size() - 1;
    int m = -1;
    int idx = -1;
    while (r >= l) {
      m = l + (r - l) / 2;  // avoid overflow for big ranges
      if (nums[m] == target) {
        idx = m;
        r = m - 1;  // Left part
      } else if (nums[m] < target)
        l = m + 1;
      else
        r = m - 1;
    }
    return idx;
  }
  int searchLast(vector<int>& nums, int& target) {
    if (nums.empty()) return -1;
    int l = 0;
    int r = nums.size() - 1;
    int m = -1;
    int idx = -1;
    while (r >= l) {
      m = l + (r - l) / 2;  // avoid overflow for big ranges
      if (nums[m] == target) {
        idx = m;
        l = m + 1;  // Right part
      } else if (nums[m] < target)
        l = m + 1;
      else
        r = m - 1;
    }
    return idx;
  }
  vector<int> searchRange2(vector<int>& nums, int target) {
    // I missed the point of this
    // Binary search will find the target in somewhere between all the
    // duplicates Let's say we want the first one -> search the left part again
    // and again until Want the last one? -> search the right part again Time
    // O(log n)
    return {searchFirst(nums, target), searchLast(nums, target)};
  }

 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    auto [start_it, end_it] = equal_range(nums.begin(), nums.end(), target);
    if (start_it == end_it) return {-1, -1};
    // Note: Points to the upperbound -> Next greater Element
    return {(int)(start_it - nums.begin()), (int)(end_it - nums.begin()) - 1};
  }
};
// @lc code=end
