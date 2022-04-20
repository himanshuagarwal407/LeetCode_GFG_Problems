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
class BSTIterator {
private:
    TreeNode* head = new TreeNode(0);
    
public:
    TreeNode* inorder(TreeNode* curr, TreeNode* prev)
    {
        if(curr==nullptr)
            return prev;
        
        TreeNode* temp = inorder(curr->left, prev);
        temp->right=curr;
        temp->left=nullptr;
        
        return inorder(curr->right, temp->right);
    }
    
    BSTIterator(TreeNode* root) {
        inorder(root, head);
    }
    
    int next() {
        head=head->right;
        return head->val;
    }
    
    bool hasNext() {
        return head->right!=nullptr;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */