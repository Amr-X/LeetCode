/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
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

#include <queue>

using namespace std;
class Solution {
public:
    // Iterative
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;

        TreeNode* curr = nullptr;
        queue<TreeNode*> queue;
        queue.push(root);

        int sum {};
        while(!queue.empty()){
            size_t size = queue.size();
            sum = 0;
            for (size_t i = 0; i < size; i++)
            {
                curr = queue.front(); queue.pop();

                sum += curr->val;
                if(curr->left){
                    queue.push(curr->left);
                }
                if(curr->right){
                    queue.push(curr->right);
                }
            }
            // Next Level
        }
        return sum;
    }


    // I hate std::pair -> Names of first and second.

    // Much better
    // struct result
    // {
    //     int sum;
    //     int depth;
    // };

    // Recursive
    // Please Work First Try -> Im Proud of myself if it did
    // result  deepestLeavesSum(TreeNode* root,int depth){
    //     if(!root){return {0,depth};} // Issue here - If depth is 100000 with value returned as zero

    //     // Don't worry about it being a leaf node in earlier depth (Not at deepest)
    //     if(!root->left && !root->right){ // Leaf Node return it's value and at what depth
    //         return {root->val,depth}; 
    //     }
    //     // Do same left and right 
    //     result left = deepestLeavesSum(root->left,depth+1);
    //     result right = deepestLeavesSum(root->right,depth+1);

    //     // Based on the sum with the Deepest We take it's sum only 
    //     if(left.depth > right.depth) // Left is deeper
    //         return {left.sum,left.depth};
    //     else if( left.depth == right.depth) // If both at same depth We add them together
    //         return {left.sum + right.sum,left.depth};

    //     return {right.sum,right.depth}; // Right is deeper
    // }

    // int deepestLeavesSum(TreeNode* root) {
    //     auto [sum , depth] = deepestLeavesSum(root, 0); // Do it at first root 
    //     return sum; // We care about the sum
    // }
};
// @lc code=end

