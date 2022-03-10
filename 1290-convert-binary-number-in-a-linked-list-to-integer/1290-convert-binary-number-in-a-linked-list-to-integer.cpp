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
    int getDecimalValue(ListNode* head) {
        vector<int> v;
        v.push_back(head->val);
        
        head=head->next;
        while(head)
        {
            v.push_back(head->val);
            head=head->next;
        }
        
        int ans=0, k=1;
        for(int i=v.size()-1; i>=0; i--)
        {
            ans += v[i]*k;
            k *= 2;
        }
        
        return ans;
    }
};