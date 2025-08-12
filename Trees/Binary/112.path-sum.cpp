/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <stack>
using namespace std;

class Solution {
public:
    // - Unfinished
    // bool hasPathSumI(TreeNode* root, int targetSum) {
    //     stack<int> stack;
    //     TreeNode* curr = root;
    //     int currentSum{0};
    //     while(curr || !stack.empty()){
    //         if(curr){
    //             currentSum += curr->val;
    //             stack.push(curr);
    //             curr = curr->left;
    //         }else{ // At End of a Branch
    //             curr = stack.top();stack.pop();
    //             currentSum -= curr->val;
    //             curr = curr->right;
    //         }
    //     }
    // }


    bool hasPathSum(TreeNode* root, int targetSum) {
        // test case:[]
        // 0 -> Shouldn't that work as true?
        // Lol people are arguing about it

        

        // Sleeping is helpful
        if(root){ // isn't null
            if(!root->right && !root->left && targetSum == root->val){ // last node val == to target
                return true;
            }
            int newSum{targetSum-(root->val)}; // Double it and give to next two persons
            return (hasPathSum(root->right,newSum) || hasPathSum(root->left,newSum));
        }
        return false; // I guess im wrong
    }
};
// @lc code=end

