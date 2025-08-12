/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){return {};}
        vector<vector<int>> result;
        deque<TreeNode*> queue; // the mystery part
        TreeNode* curr{};
        queue.push_back(root);
        int level = 0;

        while(!queue.empty()){
            size_t q_size = queue.size();
            vector<int> temp;
            temp.reserve(q_size);

            if(level % 2 == 0){ // 0,2,4 , Even level - Normal dequeueing from front
                for(int i = 0; i < q_size;++i){
                    curr = queue.front(); queue.pop_front();
                    temp.push_back(curr->val);
                    if(curr->left)
                        queue.push_back(curr->left);
                    if(curr->right)
                        queue.push_back(curr->right);
                }
            }else{ // Odd Level -> From End Side
                // Literally the inverse
                for(int i = 0; i < q_size;++i){
                    curr = queue.back(); queue.pop_back();
                    temp.push_back(curr->val);
                    // Notice how right is first - before left
                    if(curr->right)
                        queue.push_front(curr->right);
                    if(curr->left)
                        queue.push_front(curr->left);
                }
            }
            result.push_back(temp);
            level++;
        }
        return result;
    }
};
// @lc code=end

