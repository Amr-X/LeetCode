/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
class Solution {
public:
    // I Got A Little Bit Off....
    // I Won't Underestimate Any Question From Now On
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int digit = l1->val + l2->val;
        int carry = digit / 10;
        if(carry){digit%=10;}

        ListNode* curr = new ListNode(digit);
        ListNode* first_node = curr;
        l1 = l1->next; l2 = l2->next;
        
        while(l1 && l2){
            digit = l1->val + l2->val + carry;
            carry = digit / 10;
            if(carry){digit%=10;}
            curr->next = new ListNode(digit);
            curr = curr->next;
            l1 = l1->next; l2 = l2->next;
        }
        while(l1){
            digit = l1->val + carry;
            carry = digit / 10;
            if(carry){digit%=10;}
            curr->next = new ListNode(digit);
            curr = curr->next;
            l1 = l1->next; 
        }
        while(l2){
            digit = l2->val + carry;
            carry = digit / 10;
            if(carry){digit%=10;}
            curr->next = new ListNode(digit);
            curr = curr->next;
            l2 = l2->next;
        }
        (carry)?curr->next = new ListNode(carry):0;
        return first_node;
    }
};
// @lc code=end

