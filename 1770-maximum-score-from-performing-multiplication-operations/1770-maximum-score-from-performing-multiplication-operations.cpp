class Solution {
public:
    int solve(vector<int>& nums, vector<int>& multi, int l, int n, int  ind, int m, vector<vector<int>>& dp)
    {
        if(ind==m)
            return 0;
           
        if(dp[l][ind]!=INT_MIN)
            return dp[l][ind];
        
        int a = nums[l]*multi[ind] + solve(nums, multi, l+1, n, ind+1, m, dp);
        int b = nums[n-1-(ind-l)]*multi[ind] + solve(nums, multi, l, n, ind+1, m, dp);
        
        return dp[l][ind]=max(a, b);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multi) {
        int n=nums.size();
        int m=multi.size();
                
        vector<vector<int>> dp(m+1, vector<int>(m+1, INT_MIN));
        return solve(nums, multi, 0, n, 0, m, dp);
    }
};