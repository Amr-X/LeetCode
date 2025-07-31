/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
    ListNode* middleNode(ListNode* head) {
       // Fast and Slow -> Fast at end Slow at middle 
       if(!head || !head->next) return head;

       ListNode* first = head;
       ListNode* second = head;

        while(second && second->next){
            first = first->next;
            second = second->next;
            second = (second->next)?second->next:second;
        }
        return first;
    }
};
// @lc code=end

