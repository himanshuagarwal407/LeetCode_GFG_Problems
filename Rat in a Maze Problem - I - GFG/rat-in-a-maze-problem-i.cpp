// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i, int j, vector<vector<int>> &maze, int n, string move, vector<string>& v,
                             int diri[], int dirj[], vector<vector<int>>& vis)
    {
        if(i==n-1 && j==n-1)
        {
            v.push_back(move);
            return;
        }    
        
        string moves = "DLRU";
        for(int k=0; k<4; k++)
        {
            int newI = i+diri[k];
            int newJ = j+dirj[k];
            
            if(newI>=0 && newI<n && newJ>=0 && newJ<n && maze[newI][newJ]==1 && !vis[newI][newJ])
            {
                vis[i][j]=1;
                solve(newI, newJ, maze, n, move+moves[k], v, diri, dirj, vis);
                vis[i][j]=0;
                
            }
        }
    }
                
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        vector<string> v;
        vector<vector<int>> vis(n, vector<int>(n,0));
        vis[0][0]=1;
        
        int di[] = {+1, 0, 0, -1}; 
        int dj[] = {0, -1, 1, 0}; 
        
        if(maze[n-1][n-1]!=1)
            return v;
        if(maze[0][0]==1)
            solve(0, 0, maze, n, "", v, di, dj, vis);
        
        return v;
        // Your code goes here
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends