/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <string>
#include <stack> // Use Vector Also
using namespace std;

class Solution {
public:
    bool is_closing(char ch){
        return(ch == ']' || ch == ')' || ch == '}'); // How '"' is closing???
    }
    bool is_opening(char ch){
        return(ch == '[' || ch == '(' || ch == '{'); 
    }
    char opening(char ch){
        if (ch == ')') return '(';
        if (ch == ']') return '[';
        if (ch == '}') return '{';
        return ' ';
    }
    // Input: s = "()"
    // Output: true

    bool isValid(string string) {
        stack<char> stack;
        for (auto &ch : string)
        {
           if(is_closing(ch)){ // ) ]
            if(!stack.empty() && stack.top() == opening(ch)){ stack.pop();} 
            else{ return false; }
           }
           else if(is_opening(ch)){ stack.push(ch); } // ( [
        }
        return stack.empty();
    }
};
// @lc code=end

