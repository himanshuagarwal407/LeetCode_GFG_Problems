// { Driver Code Starts
//

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


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    int k=0;
    public:
    Node* buildTreeHelp(int in[], int i, int j, int pre[], int n)
    {
        if(k==n || j<0 || i>j)
            return nullptr;
            
        Node* root = (struct Node*)malloc(sizeof(Node));
        root->data = pre[k];
        
        auto it = find(in+i, in+j+1, pre[k]);
        int ind = distance(in, it);
        k++;
        
        root->left = buildTreeHelp(in, i, ind-1, pre, n);
        root->right = buildTreeHelp(in, ind+1, j, pre, n);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        Node* root = (struct Node*)malloc(sizeof(Node));
        root->data = pre[0];
        
        auto it = find(in, in+n, pre[k++]);
        int ind = distance(in, it);
        
        root->left = buildTreeHelp(in, 0, ind-1, pre, n);
        root->right = buildTreeHelp(in, ind+1, n-1, pre, n);
        
        return root;
        // Code here
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends