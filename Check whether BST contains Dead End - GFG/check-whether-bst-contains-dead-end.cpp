// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}

// } Driver Code Ends


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */

void inorder(Node* root, set<int>& v, set<int>& v1)
{
    if(!root)
        return;
        
    inorder(root->left, v, v1);
    v.insert(root->data);
    if(!root->left && !root->right)
        v1.insert(root->data);
    inorder(root->right, v, v1);
    
}

bool isDeadEnd(Node *root)
{
    set<int> v;
    set<int> v1;
    
    inorder(root, v, v1);
    
    if(v1.find(1)!=v1.end() && v.find(2)!=v.end())
        return true;
        
    for(auto it=v1.begin(); it!=v1.end(); it++)
    {
        int x=*it;
        if(v.find(x-1)!=v.end() && v.find(x+1)!=v.end())
            return true;
    }
    
    return false;
    //Your code here
}