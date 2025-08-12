/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root){return nullptr;}
        // Edge case
        if(depth == 1){
            root = new TreeNode(val,root,nullptr);
            return root;
        }

        queue<TreeNode*> queue; 
        queue.push(root);

        TreeNode* curr{};
        int curr_depth = 1;

        while(!queue.empty()){
            if(curr_depth == depth-1) // Is it where we should insert?
                break; // Get out we have previous in the queue now

            size_t q_size = queue.size();
            for(int i = 0; i < q_size;++i){
                curr = queue.front(); queue.pop();
                if(curr->left)
                    queue.push(curr->left);
                if(curr->right)
                    queue.push(curr->right);
            }
            curr_depth++; // That is next level
        }
        
        while(!queue.empty()){
            curr = queue.front(); queue.pop();

            TreeNode* curr_left = curr->left;
            TreeNode* curr_right = curr->right;

            curr->left = new TreeNode(val,curr_left,nullptr);
            curr->right = new TreeNode(val,nullptr,curr_right);
        }
        return root;
    }
};
// @lc code=end

