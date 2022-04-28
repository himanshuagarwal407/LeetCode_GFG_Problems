class Solution {
public:
    
    void fact(int n, vector<int>& dp)
    {
        for(int i=1; i<=n; i++)
        {
            dp[i]=dp[i-1]*i;
        }
    }
    
    string getPermutation(int n, int k) {
        string res="";
        
        vector<int> dp(n+1,1);
        fact(n, dp);
        
        vector<int> v;
        for(int i=1; i<=n; i++)
            v.push_back(i);
        
        k--;
        while(n>0)
        {
            int grp_len = dp[n-1];
            int ind = k/grp_len;
           
            res += to_string(v[ind]);
            
            v.erase(v.begin()+ind);
            k=k%grp_len;
            n--;
        }
        
        return res;
    }
};