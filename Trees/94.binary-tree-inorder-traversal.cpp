/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
#include <vector>

class Solution {
public:
    void inorder(TreeNode* root,vector<int>& vec){
       if(!root){
        return;
       }
       inorder(root->left,vec);
       vec.push_back(root->val);
       inorder(root->right,vec); 

    }
    vector<int> inorderTraversal(TreeNode* root) {
       // What Should Be Used Here? Iterative or Recursive?
       // Recursive -> Simple, Could Overflow
       // Iterative -> Not Simple, With Deep Tree 
       vector<int> result;
       inorder(root,result);
       return result;
    }
};
// @lc code=end

