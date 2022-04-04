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
    vector<int> v;
    void inorder(TreeNode* root)
    {
        if(!root)
            return ;
        
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        
        if(root->val==key)
        {
            if(!root->left && !root->right)
            {
                delete(root);
                return nullptr;
            }
            else if(!root->left)
                root=root->right;
            else if(!root->right)
                root=root->left;
            else
            {
                v.clear();
                inorder(root->left);
                int n=v.size();
                int x=v[n-1];
                
                root->val=x;
                root->left=deleteNode(root->left, x);
            }    
        }
        else if(root->val > key)
        {
            root->left=deleteNode(root->left, key);
        }
        else
            root->right=deleteNode(root->right, key);
        
        return root;
    }
};