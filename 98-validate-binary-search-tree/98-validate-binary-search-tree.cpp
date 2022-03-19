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
    vector<int> inorder;
    
    void inorderTraversal(TreeNode* root)
    {
        if(!root)
            return;
        
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        inorderTraversal(root);
        
        int n=inorder.size(),i=0;
        while(i<n-1)
        {
            if(inorder[i] >= inorder[i+1])
                return false;
            i++;
        }
        
        return true;
    }
};