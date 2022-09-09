class Solution {
    // int z=60;
    // vector<int> dp(z, -1);
public:
    int bitCount(int n, vector<int>& dp)
    {
        if(dp[n]!=-1)
            return dp[n];
        
        int count=0;
        while(n)
        {
            if(n&1)
                count++;
            n=n>>1;
        }
        
        return dp[n] = count;
    }
    
    vector<string> solve(int a)
    {
        if(a==0)
            return {"0"};
        if(a==1)
            return {"1", "2", "4", "8"};
        if(a==2)
            return {"3", "5", "6", "9", "10"};
        if(a==3)
            return {"7", "11"};
        
        return {};
    }
    
    vector<string> solve2(int a, vector<int>& dp)
    {
        if(a==0)
            return {"00"};
        if(a>5)
            return {};
        
        
        vector<string> v;
        for(int i=1; i<60; i++)
        {
            if(bitCount(i, dp)==a)
            {
                if(i<10)
                    v.push_back("0"+to_string(i));
                else
                    v.push_back(to_string(i));
            }
        }
        
        return v;
    }
    
    
    vector<string> readBinaryWatch(int n) {
        if(n>8)
            return {};
        
        vector<string> ans;
        vector<int> dp(60, -1);
        
        for(int i=0; i<=min(3, n); i++)
        {
            vector<string> hour = solve(i);
            vector<string> min = solve2(n-i, dp);
            
            if(min.size()==0)
                continue;
            
            int h=hour.size(), m=min.size();
            for(int k=0; k<h; k++)
            {
                for(int j=0; j<m; j++)
                {
                    ans.push_back(hour[k]+":"+min[j]);
                }
            }
        }
        
        return ans;
    }
};