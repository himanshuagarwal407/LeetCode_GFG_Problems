

class Solution {
public:
    bool solve(string s, int n, int k, set<int>& st)
    {
        if(s.size()==n)
        {
            st.insert(stoi(s));
            return true;
        }
        
        int x=stoi(s)%10;
        
        bool a=false, b=false;
        if(x+k<=9 && x+k>=0)
            a=solve(s+to_string(x+k), n, k, st);
        if(x-k<=9 && x-k>=0)
            b=solve(s+to_string(x-k), n, k, st);
        
        return a+b;
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        set<int> st;
        
        for(int i=1; i<=9; i++)
        {
            string s=to_string(i);
            solve(s, n, k, st);
        }
        
        for(auto x:st)
            ans.push_back(x);
        return ans;
    }
};