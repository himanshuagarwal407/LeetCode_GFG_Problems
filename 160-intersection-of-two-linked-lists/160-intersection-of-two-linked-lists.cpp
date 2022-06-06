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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        
        while(temp1)
        {
            temp1->val *= -1;
            temp1=temp1->next;
        }
        
        ListNode* res = new ListNode();
        res = nullptr;
        
        while(temp2)
        {
            if(temp2->val<0)
            {
                res=temp2;
                break;
            }
            
            temp2=temp2->next;
        }
        
        temp1=headA;
        while(temp1)
        {
            temp1->val *= -1;
            temp1=temp1->next;
        }
        
        return res;
    }
};