/*
 * @lc app=leetcode id=668 lang=cpp
 *
 * [668] Kth Smallest Number in Multiplication Table
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
// Very good Problem
class Solution {
  // The Hint: How many numbers <= x in m*n table
  int count(int m_n, int m, int n) {
    // Instead Of Brute Force O(m*n)
    int count = 0;
    for (int i = 1; i <= m; i++) {
      count += min(n, m_n / i);  // I Don't understand the m_n/m
    }
    return count;
  }

 public:
  int findKthNumber(int m, int n, int k) {
    int l = 1;
    int r = m * n;
    int save_number = 0;
    while (l <= r) {
      int m_n = l + (r - l) / 2;
      // count: How many <= 6(m_n) in table of m * n
      if (count(m_n, m, n) >= k) {
        save_number = m_n;
        r = m_n - 1;
      } else
        l = m_n + 1;
    }
    return save_number;
  }
};
// @lc code=end
