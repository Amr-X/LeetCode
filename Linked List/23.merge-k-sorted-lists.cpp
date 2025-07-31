/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
#include <queue> // I'm Not Implementing That ofc
#include <list> // Feels Like Cheating
#include <functional>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       // First Hard Problem
       // Solution -> 
       //  - Mark Row Of Nodes
       //  - Put Them In Array To Be Sorted  (Yeah, Priority_Queue)
       //  - Create For Them A List and repeat 
        
        
        std::priority_queue<int,std::vector<int>,std::greater<int>> queue;

        // If I can just stop overthinking...

        // Fill
        for (auto &list : lists)
        {
            ListNode* curr{list};
            while(curr){
                queue.push(curr->val);
                curr = curr->next;
            }
        }
        
        ListNode* head{new ListNode()};
        ListNode* last{head};
        // Out of Queue - Sorted
        while(!queue.empty()){
            last->next = new ListNode(queue.top());
            last = last->next;
            queue.pop();
        }
        
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head; 
    }
};
// @lc code=end

