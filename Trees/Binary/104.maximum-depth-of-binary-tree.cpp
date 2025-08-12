/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode* root) {
       // Null tree
       if(!root){return 0;}

       // Get right depth
       int right_depth = maxDepth(root->right);
       // Get left depth
       int left_depth = maxDepth(root->left);
       // Which is Deeper?
       return (right_depth > left_depth)? right_depth+1:left_depth+1;
       // That Deeper Depth + 1 <- Root first node


       // What is the iterative approach? AI Just to look at 
    //    std::queue<TreeNode*> q;
    //    q.push(root);
    //    int depth = 0;
    //    while (!q.empty()) {
    //        int levelSize = q.size(); // Number of nodes at this level
    //        for (int i = 0; i < levelSize; ++i) {
    //            TreeNode* node = q.front(); q.pop();
    //            if (node->left) q.push(node->left);
    //            if (node->right) q.push(node->right);
    //        }
    //        depth++; // Finished processing one level
    //    }
    //        }
};
// @lc code=end

