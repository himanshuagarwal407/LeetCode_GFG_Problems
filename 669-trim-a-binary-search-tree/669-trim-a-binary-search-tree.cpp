/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void  preOrderTraversal(TreeNode* root, vector<int>& preOrder)
    {
        if(!root)
            return ;
        
        preOrder.push_back(root->val);
        if(root->left)
            preOrderTraversal(root->left, preOrder);
        if(root->right)
            preOrderTraversal(root->right, preOrder);
    
    }
    
    TreeNode* insert(TreeNode* head, int temp)
    {
        
        if(!head)
        {
            head = new TreeNode(temp);
            return head;
        }
        
        if(temp < head->val)
            head ->left = insert(head->left, temp);
        else if(temp > head->val)
            head->right = insert(head->right, temp);
            
        return head;
    }
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        vector<int> preOrder;
        
        preOrderTraversal(root, preOrder);
        
        TreeNode* head = new TreeNode();
        head=head->left;
        int n=preOrder.size();
        
        for(int i=0; i<n; i++)
        {
            int temp = preOrder[i];
            if(temp >=low && temp <= high)
            {
                if(!head)
                {
                    head = new TreeNode(temp);
                }
                else if(temp < head->val)
                    head ->left = insert(head->left, temp);
                else if(temp > head->val)
                    head->right = insert(head->right, temp);
            }
        }
        
        return head;
    }
};