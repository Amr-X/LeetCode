/*
 * @lc app=leetcode id=1669 lang=cpp
 *
 * [1669] Merge In Between Linked Lists
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* first_remove{};
        ListNode* first_link{};
        ListNode* second_link{};

        ListNode* last_list2{};
      
        // Get Last list2
        ListNode* curr{list2};
        while(curr->next){
            curr = curr->next;
        }
        last_list2 = curr;

        // Get first_link
        curr = list1;
        for (size_t i = 0; i < a-1; i++)
        {
            curr = curr->next;
        }
        first_link = curr;
        // Get first_remove 
        first_remove = first_link->next;
        

        // Get second_link
        curr = first_remove;
        for (size_t i = 0; i < b-a+1; i++)
        {
            curr = curr->next;
        }
        second_link = curr;

        // Connect
        first_link->next = list2;
        last_list2->next = second_link;

        // Delete  - Fuck You Best State Over Memory Leak
        // curr = first_remove;
        // ListNode* temp{};
        // while(curr != second_link){
        //     temp = curr;
        //     curr = curr->next;
        //     delete temp;
        // }

        return list1;
    }
};
// @lc code=end

