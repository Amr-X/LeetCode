/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start
class Solution {
 public:
  long coins_at(long k) { return k * (k + 1) / 2; }
  int arrangeCoins(int n) {
    // for the o(1) -> You need to solve (1+2+3+4..+x = n) for x
    // get the floor value

    // Wow! 3H Didn't write a single line
    // Imagine the Number lines

    long r = n;
    long l = 0;
    long save = 0;
    while (r >= l) {
      long m = l + (r - l) / 2;
      if (coins_at(m) <= n) {
        save = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return (int)save;
  }
};
// @lc code=end
