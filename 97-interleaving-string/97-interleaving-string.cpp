class Solution {
public:
    unordered_map<string, bool> mp;
    
    bool solve(string s1, string s2, string s3, int a, int b, int c, int i, int j, int k)
    {
        if(k==c)
            return true;
        
        string key = to_string(i)+"_"+to_string(j)+"_"+to_string(k);
        
        if(mp.find(key)!=mp.end())
            return mp[key];
        
        if(i==a)
            return mp[key] = (s2[j]==s3[k]) ? solve(s1, s2, s3, a, b, c, i, j+1, k+1) : false;
        if(j==b)
            return mp[key] = (s1[i]==s3[k]) ? solve(s1, s2, s3, a, b, c, i+1, j, k+1) : false;
        
        bool x=false, y=false;
        
        if(s1[i]==s3[k])
            x=solve(s1, s2, s3, a, b, c, i+1, j, k+1);
        if(s2[j]==s3[k])
            y=solve(s1, s2, s3, a, b, c, i, j+1, k+1);
        
        return mp[key] = x or y;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int a=s1.size(), b=s2.size(), c=s3.size();
        
        if((a+b)!=c)
            return false;
        
        if(solve(s1, s2, s3, a, b, c, 0, 0, 0))
            return true;
        return false;
    }
};