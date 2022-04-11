// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void solve(int col, int n, vector<int>& v, vector<vector<int>>& ans, vector<vector<int>>& board,
                vector<int>& lRow, vector<int>& uDiagonal, vector<int>& lDiagonal)
    {
        if(col == n)
        {
            ans.push_back(v);
            return;
        }
        
        for(int row=0; row<n; row++)
        {
            if(lRow[row]==0 && lDiagonal[col+row]==0 && uDiagonal[n-1 + col-row]==0)
            {
                board[row][col]=1;
                v.push_back(row+1);
                lRow[row]=1;
                lDiagonal[col+row]=1;
                uDiagonal[n-1 + col-row]=1;
                
                solve(col+1, n, v, ans, board, lRow, uDiagonal, lDiagonal);
                
                board[row][col]=0;
                v.pop_back();
                lRow[row]=0;
                lDiagonal[col+row]=0;
                uDiagonal[n-1 + col-row]=0;
            }
        }
            
    }
    
    vector<vector<int>> nQueen(int n) {
        if(n==1)
            return {{1}};
            
        vector<int> v;
        vector<vector<int>> ans;
        
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<int> lRow(n, 0), uDiagonal(2*n -1, 0), lDiagonal(2*n -1, 0);
        
        solve(0, n, v, ans, board, lRow, uDiagonal, lDiagonal);
        
        return ans;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends