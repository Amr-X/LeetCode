/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;


        ListNode* slow = head; 
        ListNode* fast = head; 

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next;
            if(fast->next){
                fast = fast->next;
            }else{return false;} 

            if(slow == fast){
                return true;
            }
        }
        return false;
        
    }
};
// @lc code=end

