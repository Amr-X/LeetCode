/*
 * @lc app=leetcode id=1482 lang=cpp
 *
 * [1482] Minimum Number of Days to Make m Bouquets
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  bool canMakeBouquets(int day, vector<int>& bloomDay, int m, int k) {
    int bouquets = 0;
    int count = 0;
    for (int i = 0; i < bloomDay.size(); i++) {
      if (bloomDay[i] <= day) {
        if (++count == k) {
          count = 0;
          if (++bouquets == m) break;
        }
      } else
        count = 0;
    }
    return (bouquets >= m);
  }

 public:
  int minDays(vector<int>& bloomDay, int m, int k) {
    if ((long)m * k > bloomDay.size()) return -1;
    // Imagine all The days and calculating if for day = x to make the m
    // bouquets Instead of saying wait 1000 days (Doable) good let's do 999 and
    // go one by one (linear) We jump to 500 and so on (binary search) - Again
    // monotonic function We are looking for the first T of the values

    int l = 0;
    // Faster? get max_element if we waited that much time all the flowers will
    // be bloomed any value between (max_element,inf) is True
    int r = *max_element(bloomDay.begin(), bloomDay.end());
    int save_day = r;
    while (l <= r) {
      int day = l + (r - l) / 2;
      if (canMakeBouquets(day, bloomDay, m, k)) {
        save_day = day;
        r = day - 1;
      } else
        l = day + 1;
    }
    return save_day;
  }
};
// @lc code=end
