/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    // ListNode* reverseList(ListNode* head) {
    //     if(!head) return nullptr;
    //     // Got It -> Don't Have to Return head->next Where I already can access it from head
    //     if(head->next == nullptr){
    //         return head;
    //     }
    //     // Go Next
    //     // Then, Link
    //     ListNode* last = reverseList(head->next);
    //     head->next->next = head;
    //     head->next = nullptr;
    //     return last;
    // }

    ListNode* reverseList(ListNode* head){
        // Iterative
        if(!head || !head->next)return head;

        ListNode* prev = nullptr; 
        ListNode* curr = head;
        ListNode* next = head->next;

        while(next){
            curr->next = prev; // Link
            // Move
            prev = curr;
            curr = next;
            next = next->next;
        }
        // Last one
        curr->next = prev;
        return curr;
    }
};
// @lc code=end

