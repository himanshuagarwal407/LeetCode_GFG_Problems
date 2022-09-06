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
    bool traversal(TreeNode* root)
    {
        if(!root)
            return false;
        
        bool a=traversal(root->left);
        if(!a)
            root->left=NULL;
        
        bool b=traversal(root->right);
        if(!b)
            root->right=NULL;
        
        if(root->val==1)
            return true;
        return a||b;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!traversal(root))
            return nullptr;
        
        return root;
    }
};