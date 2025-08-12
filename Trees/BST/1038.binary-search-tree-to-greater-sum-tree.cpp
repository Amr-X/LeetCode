/*
 * @lc app=leetcode id=1038 lang=cpp
 *
 * [1038] Binary Search Tree to Greater Sum Tree
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
private:
    int sum{0};
public:

    void toGst(TreeNode* node){
        // Wow, This is the problem - retains value after every testcase
        // static int sum{0};

        if(!node){
            return;
        }
        toGst(node->right);
        sum += node->val;
        node->val = sum;
        toGst(node->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        // First tree problem
        // Inorder -> I think it is    

        // Wtf, I coded it in 1 min .......????????>??>???/
        toGst(root);
        return root;
    }
};
// @lc code=end

