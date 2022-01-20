// Source: https://leetcode.com/problems/swap-nodes-in-pairs/
// Author: Himanshu Agarwal
// Date: 20/01/2022
  
/*
  
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)


Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]


Example 2:
Input: head = []
Output: []


Example 3:
Input: head = [1]
Output: [1]
  
*/

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
        if(!head)
            return nullptr;
        if(!head->next)
            return head;
        
        ListNode* temp = head;
        ListNode* prev = NULL;
        
        ListNode* d = temp->next;
        temp->next=temp->next->next;
        d->next=temp;
        prev=temp;
        if(temp->next)
            temp=temp->next;
        else
            return d;
        head=d;
        
        while(temp->next && temp->next->next)
        {
            d = temp->next;
            temp->next=temp->next->next;
            d->next=temp;
            prev->next=d;
            prev=temp;
            temp=temp->next;
        }
        if(!temp->next)
            return head;
        
        d = temp->next;
        temp->next=NULL;
        d->next=temp;
        prev->next=d;
        
        return head;
    }
};
