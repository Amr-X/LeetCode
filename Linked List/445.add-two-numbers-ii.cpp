/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
#include <stack>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // "When you wanna go deep and back, think stack, baby!", Someone Said

        // I didn't ever think that a simple addition problem would hunt me like this

        // Time: O(m+n) Space: O(m+n) <- Stack 
        std::stack<ListNode*> l1_stack;
        std::stack<ListNode*> l2_stack;

        {
            // Fill Stack
            ListNode* curr1 = l1;
            ListNode* curr2 = l2;

            while(curr1){
                l1_stack.push(curr1);
                curr1 = curr1->next;
            }
            while(curr2){
                l2_stack.push(curr2);
                curr2 = curr2->next;
            }
        }

        //Pop
        ListNode* head{};
        int carry = 0;
        // This is hideous to look at - Lots of checks
        while(!l1_stack.empty() || !l2_stack.empty()){
            int first_digit = (!l1_stack.empty())?l1_stack.top()->val:0;
            int sec_digit = (!l2_stack.empty())?l2_stack.top()->val:0;
            if(!l1_stack.empty()) l1_stack.pop();
            if(!l2_stack.empty()) l2_stack.pop();

            int digit = first_digit+sec_digit+carry;
            carry = digit/10;
            (carry)?digit %= 10:0;

            head = new ListNode(digit,head);
        }
        // And Ofc Last Carry
        if(carry){
            head = new ListNode(carry,head);
        }
        return head;
    }
};
// @lc code=end

