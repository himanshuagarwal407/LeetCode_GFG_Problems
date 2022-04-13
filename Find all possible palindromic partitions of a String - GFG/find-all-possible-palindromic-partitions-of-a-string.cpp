// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool isPalindrom(string s)
    {
        int i=0, j=s.size()-1;
        while(i<=j)
        {
            if(s[i]!=s[j])
                return false;
                
            i++;
            j--;
        }
        
        return true;
    }
  
    void solve(string s, int i, int j, vector<string>& v, vector<vector<string>>& ans, int n)
    {
        if(i+j>n)
        {
            if(i==n)
            {
                ans.push_back(v);
                return;
            }
            return;
        }
        
        string s1=s.substr(i,j);
        
        if(isPalindrom(s1))
        {
            v.push_back(s1);
            solve(s, i+j, 1, v, ans, n);
            v.pop_back();
        }
        solve(s, i, j+1, v, ans, n);
        
    }
  
    vector<vector<string>> allPalindromicPerms(string s) {
        // code here
        int n=s.size();
        
        vector<string> v;
        vector<vector<string>> ans;
        
        solve(s, 0, 1, v, ans, n);
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends