// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Author: Himanshu Agarwal
// Date: 20/01/2022

/*

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]


Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return nullptr;
        if(!head->next)
            return head;
        
        ListNode* temp = head;
        ListNode* prev = NULL;
        int x=temp->val;
        
        while(temp->next->val==x)
        {  
            temp=temp->next;
            while(temp->val==x)
            {
                if(temp->next)
                    temp=temp->next;
                else
                    return NULL;
            }
            head=temp;
            if(!temp->next)
                return head;
            x=temp->val;
        }
        
        
        if(temp->next)
        {
            while(temp->next!=NULL)
            {
                x=temp->val;
                if(temp->next->val == x)
                {
                    temp=temp->next;
                    while(temp->next && temp->next->val==x)
                        temp=temp->next;
        
                    if(temp->next)
                    {
                        temp=temp->next;
                        prev->next=temp;   
                    }
                }
                else
                {
                    prev=temp;
                    temp=temp->next;
                }
            }
        }
        else
            return head;
        
        if(temp->val!=x)
            prev->next=temp;
        else
            prev->next=NULL;
        
        return head;
    }
};
