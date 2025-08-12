/*
 * @lc app=leetcode id=2331 lang=cpp
 *
 * [2331] Evaluate Boolean Binary Tree
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
class Solution {
public:
    enum boolean {False,True,OR,AND};

    bool evaluateTree(TreeNode* root) {
        if(root->val == OR) return evaluateTree(root->left) || evaluateTree(root->right);
        if(root->val == AND) return evaluateTree(root->left) && evaluateTree(root->right);
        // Otherwise
        return root->val;
    }


};
// @lc code=end

