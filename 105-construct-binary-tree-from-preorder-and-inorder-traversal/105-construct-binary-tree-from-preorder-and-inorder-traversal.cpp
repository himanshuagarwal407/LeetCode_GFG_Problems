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
    int preIndex=0;
    TreeNode* Tree(vector<int> pre, vector<int> in, int start, int end)
    {
        
        
        if(start>end)
            return NULL;
        
        int data=pre[preIndex];
        TreeNode* newNode = new TreeNode(data);
        preIndex++;
        
        if(start==end)
            return newNode;
        
        int inIndex;
        for(int i=start; i<=end; i++)
            if(in[i]==newNode->val)
                inIndex=i;
        
        newNode->left=Tree(pre, in, start, inIndex-1);
        newNode->right=Tree(pre, in, inIndex+1, end);
        
        return newNode;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        
        int start=0;
        int end=inorder.size()-1;
        root=Tree(preorder, inorder, start, end);
        
        return root;
    }
};