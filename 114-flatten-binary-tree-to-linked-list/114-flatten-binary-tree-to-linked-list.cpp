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
    vector<TreeNode*> v;
public:
    void preOrder(TreeNode* root)
    {
        if(!root)
            return;
        
        v.push_back(root);
        preOrder(root->left);
        preOrder(root->right);
    }
    
    void flatten(TreeNode* root) {
        if(!root)
            return ;
        
        preOrder(root);
        
        TreeNode* temp=root;
        for(int i=1; i<v.size(); i++)
        {
            temp->left=NULL;
            temp->right=v[i];
            
            temp=temp->right;
        }
    }
};