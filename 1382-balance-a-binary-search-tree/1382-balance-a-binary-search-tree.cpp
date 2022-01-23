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
private: 
    vector<TreeNode*> inorder;
    void inorderTraversal(TreeNode* root)
    {
        if(root)
        {
            inorderTraversal(root->left);
            inorder.push_back(root);
            inorderTraversal(root->right);
        }
    }
    
    TreeNode* helper(int start, int end)
    {
        if (start>end)
            return NULL;
        int mid = (start+end)/2;
        TreeNode* root = inorder[mid];
        root->left = helper(start, mid-1);
        root->right = helper(mid+1, end);
        
        return root;
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraversal(root);
        
        return helper(0, inorder.size()-1);
    }
};