/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    // Level By Level - BFS

    // int countNodes(TreeNode* root) {
    //    if(!root){
    //     return 0;
    //    }
    //    return 1 + countNodes(root->right) + countNodes(root->left);
    // }

    // int countNodes(TreeNode* root) {
    //     // Just noticed if there is null trees in level by level ....
    //     if(!root) return 0;
    //     queue<TreeNode*> queue;
    //     int sum{};
    //     TreeNode* curr{};
    //     queue.push(root);
    //     while(!queue.empty()){
    //         curr = queue.front(); queue.pop();
    //         // This Question Give a Complete Tree - So This Check is Unnecessary
    //         if(curr->left)
    //             queue.push(curr->left);
    //         if(curr->right)
    //             queue.push(curr->right);
    //         sum++;
    //     }
    //     return sum;
    // }

    // Optimal - Seen It ---> 
    #include <cmath>

    int countNodes(TreeNode* root){
        // Uses the Property of Complete Binary Tree


        // Simply put, if tree is full - both right and left could be the same count
        // that gives you hight count and since it's full then the count of nodes is pow(2,count)-1
        // if one of the count is off by one like 9 - 8 , 8 - 7 We continue as normal adding one to the result of both left tree and right tree
        if(!root)return 0;

        TreeNode* goRight{root}; int rightCount{0};
        TreeNode* goLeft{root}; int leftCount{0};

        while(goRight){rightCount++;goRight = goRight->right;}
        while(goLeft){leftCount++;goLeft = goLeft->left;}

        if(rightCount==leftCount){return std::pow(2,rightCount)-1;}

        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
// @lc code=end

