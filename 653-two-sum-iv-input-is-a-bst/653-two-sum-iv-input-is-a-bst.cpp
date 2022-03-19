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
    
    bool findTarget(TreeNode* root, int k) {
        
        inorderTraversal(root);
        int j = inorder.size()-1, i=0 ;
        
        while(i<j)
        {
            if(inorder[i]+inorder[j] < k)
                i++;
            else if(inorder[i]+inorder[j] > k)
                j--;
            else
                return true;
        }
        
        return false;
    }
};