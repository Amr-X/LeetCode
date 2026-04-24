/*
 * @lc app=leetcode id=436 lang=cpp
 *
 * [436] Find Right Interval
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 private:
  // Called SearchCeil Find the closest number to 10  - smallest value >= 10
  int searchFirst(vector<pair<int, int>>& starts, int& target) {  // target = 10
    int idx = -1;
    if (starts.empty()) return idx;
    int l = 0;
    int r = starts.size() - 1;
    int m = -1;
    while (r >= l) {
      m = l + (r - l) / 2;
      if (starts[m].first >= target) {  // 10,11,....->
        idx = m;                        // Save idx
        r = m - 1;  // Try to find a smaller (closer) on the left
      } else
        l = m + 1;
    }
    if (idx == -1) return idx;
    return starts[idx].second;  // original index
  }

  vector<int> findRightInterval1(vector<vector<int>>& intervals) {
    //  [[3,4],[2,3],[1,2]]
    vector<pair<int, int>> starts;
    starts.reserve(intervals.size());  // [start,index]
    for (int i = 0; i < intervals.size(); i++)
      starts.push_back({intervals[i].front(), i});  // i -> index

    sort(starts.begin(), starts.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) {
           return a.first < b.first;  // based on start (Each unique)
         });

    vector<int> result;
    result.reserve(intervals.size());

    for (auto& interval : intervals) {
      // [3,4]
      int idx = searchFirst(starts, interval[1]);  // interval[1] -> end
      result.push_back(idx);
    }
    return result;
  }

 public:
  // STL Based
  vector<int> findRightInterval(vector<vector<int>>& intervals) {
    vector<pair<int, int>> starts(intervals.size());
    for (int i = 0; i < intervals.size(); i++)
      starts[i] = {intervals[i].front(), i};  // i -> index

    sort(starts.begin(),
         starts.end());  // Just remembered it's default if(a!=b) return a<b

    vector<int> result(intervals.size(), -1);
    for (int i = 0; i < intervals.size(); i++) {
      int end = intervals[i][1];
      // We have vector<pair>, We need to provide is_less<pair,int>
      auto ans = lower_bound(starts.begin(), starts.end(), end,
                             [](const pair<int, int>& it, const int& value) {
                               return it.first < value;
                             });
      if (ans != starts.end()) result[i] = (*ans).second;
    }
    return result;
  }
};
// @lc code=end
