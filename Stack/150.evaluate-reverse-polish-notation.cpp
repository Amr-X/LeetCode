/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
#include<string>
#include<vector>
#include<stack> // Don't Even Need It
using namespace std;

// Input: tokens = ["1","2","+","3","*","4","-"]
// Output: 5
// Explanation: ((1 + 2) * 3) - 4 = 5
class Solution {
public:
    bool is_operand(const string& str){ //
        return ((str.size() == 1)&&(str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/'));
    }
    int calc(int first,int second,char operand){
        int result{};
        switch(operand){
            case '+': result = first + second; break;
            case '-': result = first - second; break;
            case '*': result = first * second; break;
            case '/': result = first / second; break;
        }
        return result;
    }
    int evalRPN(vector<string>& tokens) {
        // PostFix
        stack<int> stack;
        for (const auto &token : tokens)
        {
           // "1" , "2" , ..
           if(is_operand(token)){ // "+"
               int second = stack.top();stack.pop(); // 2
               int first = stack.top();stack.pop(); // 1
               char operand = token.front(); // "+"
               int result = calc(first,second,operand); // 1 + 2 = 3
               stack.push(result); // 3
           }else{
            stack.push(atoi(token.c_str()));
           }
        }
        // If Right Input - Only Result is in stack
        return stack.top();
         
    }
};
// @lc code=end

