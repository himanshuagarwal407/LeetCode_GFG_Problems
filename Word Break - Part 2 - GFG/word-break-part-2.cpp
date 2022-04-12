// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(int i, int j, string s, int m, set<string> set, int n, vector<string>&word, vector<string>& ans)
    {
        if(i+j>m)
        {
            if(i==m)
            {
                string statement=word[0];
                for(int i=1; i<word.size(); i++)
                    statement += " " + word[i];
                
                ans.push_back(statement);
                return;
            }
            else
                return;
        }
        
        string s1 = s.substr(i,j);
        if(set.find(s1)!=set.end())
        {
            if(word.empty())
                word.push_back(s1);
            else
                word.push_back(s1);
            
            solve(i+j, 1, s, m, set, n, word, ans);
            
            word.pop_back();
        }
        
        solve(i, j+1, s, m, set, n, word, ans);
        
    }

    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        set<string> set ;
        for(auto x:dict)
            set.insert(x);
        
        int m=s.size();
        vector<string>word;
        vector<string> ans;
        
        solve(0, 1, s, m, set, n, word, ans);
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends