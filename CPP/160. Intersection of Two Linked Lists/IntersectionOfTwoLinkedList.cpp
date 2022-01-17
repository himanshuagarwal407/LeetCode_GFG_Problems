//Source: https://leetcode.com/problems/intersection-of-two-linked-lists/
//Author: Himanshu Agarwal
//Date:   17/01/22

// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

/*

Example 1:
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.

Example 2:
Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Method 1:  O(n^2)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL)
            return nullptr;
        
        while(headA)
        {
            ListNode* temp = headB;
            while(temp)
            {
                if(headA == temp)
                    return temp;
                temp=temp->next;
            }
            headA=headA->next;
        }
        
        return nullptr;
    }
};


// Method 2:  O(n)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL)
            return nullptr;
        
        ListNode *temp1=headA, *temp2=headB;
        int sizeA=0, sizeB=0;
        
        while(temp1)
        {
            sizeA++;
            temp1=temp1->next;
        }
        
        while(temp2)
        {
            sizeB++;
            temp2=temp2->next;
        }
        
        int diff = abs(sizeA-sizeB);
        temp1=headA;
        temp2=headB;
        
        if(sizeA > sizeB)
        {
            while(diff!=0)
            {
                diff--;
                temp1=temp1->next;
            }
        }
        else
        {
            while(diff!=0)
            {
                diff--;
                temp2=temp2->next;
            }
        }
        
        while(temp1 && temp2)
        {
            if(temp1==temp2)
                return temp1;
            
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        return nullptr;
    }
};
