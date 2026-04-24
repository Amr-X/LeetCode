/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
    int rangeSumBST(TreeNode* root,const int& low,const int& high) {
       // Love it and hate - I still want the iterative version
       if(!root)return 0;

       if(root->val >= low && root->val <= high){
            return root->val + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
       }else if(root->val < low){ // don't care about smaller than it - so why call it?
        return rangeSumBST(root->right,low,high); // Bigger values are there
       }
       // if(root->val > high)
       return rangeSumBST(root->left,low,high); // Smaller values are there
    }
};
// @lc code=end

