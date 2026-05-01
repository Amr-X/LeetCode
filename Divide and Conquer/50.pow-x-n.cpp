/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  double myPow(double x, int m) {
    // Faster than O(n) -> O(logn)
    // Can we do x^n/2 * x^n/2
    // Yes, but if it's even and we don't even have to call it two times
    // If odd we normally do the  x*x^n-1
    // Negative? just 1/ans
    if (m == 0)
      return 1;

    bool negative = m < 0;
    long long n = m;
    if (negative)
      n = -1 * (long long)m;

    double ans = 0.0;
    if (n % 2 == 0) {
      ans = myPow(x, n / 2);
      ans *= ans;
    } else
      ans = x * myPow(x, n - 1);

    if (negative)
      ans = 1 / ans;

    return ans;
  }
};
// @lc code=end
