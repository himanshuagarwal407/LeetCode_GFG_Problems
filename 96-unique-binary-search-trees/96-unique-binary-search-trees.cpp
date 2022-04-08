#include<vector>
#include<bits/stdc++.h>

class Solution {
    
public:
    vector<int> dp;
    Solution(): dp(20,1) {};
    
    int numTrees(int n) {
        if(dp[n]!=1)
            return dp[n];
        if(n==1 || n==0)
            return 1;
        dp[n]=0;
        for(int i=1; i<=n; i++)
            dp[n] += numTrees(i-1)*numTrees(n-i);
        
        return dp[n];
    }
};