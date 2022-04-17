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
    void traversal(TreeNode* root, vector<TreeNode*>& inorder)
    {
        if(!root)
            return ;
        
        traversal(root->left, inorder);
        inorder.push_back(root);
        traversal(root->right, inorder);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> inorder;
        traversal(root, inorder);
        
        int i=0;
        for(; i<inorder.size() -1; i++)
        {
            inorder[i]->left=nullptr;
            inorder[i]->right=inorder[i+1];
        }
        inorder[i]->left=nullptr;
        inorder[i]->right=nullptr;
        
        
        return inorder[0];
    }
};