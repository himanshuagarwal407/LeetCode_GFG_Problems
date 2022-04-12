class Solution {
public:
    int invalid(string s)
    {
        stack<char> st;
        int count=0;
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(')
                st.push('(');
            else if(s[i]==')')
            {
                if(st.empty())
                    count++;
                else
                    st.pop();
            }
        }
        
        count += st.size();
        
        return count;
    }
    
    void solve(string s, int minRem, unordered_set<string>& vis, vector<string>& ans)
    {
        if(vis.find(s)!=vis.end())
            return;
        vis.insert(s);
        
        if(minRem==0)
        {
            if(invalid(s)==0)
                ans.push_back(s);
            return;
        }
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(' || s[i]==')')
            {
                string l = s.substr(0, i);
                string r = s.substr(i+1);
                
                solve(l+r, minRem-1, vis, ans);
            }
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int n=s.size();
        
        int invalidPar = invalid(s);
        
        vector<string> ans;
        unordered_set<string> visited;
        
        solve(s, invalidPar, visited, ans);
        
        return ans;
    }
};