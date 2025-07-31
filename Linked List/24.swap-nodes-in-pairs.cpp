/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
       ListNode* curr = head;
       ListNode* next = curr->next;D
       ListNode* to_go = next->next;
       ListNode* to_link = (next && next->next)?next->next->next:nullptr;
       
       head = next;

       while(curr && next){
        next->next = curr;
        curr->next = to_link;
        // Next Stage
        curr = to_go;
        next = to_link; 
        to_link = (to_link && to_link->next)?to_link->next->next:nullptr;
        to_go = (next)?next->next:nullptr;
       }
       return head;
    }
};
// @lc code=end

