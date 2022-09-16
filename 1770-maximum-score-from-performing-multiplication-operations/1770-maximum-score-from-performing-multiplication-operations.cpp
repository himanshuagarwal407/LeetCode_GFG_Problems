class Solution {
public:    
    int maximumScore(vector<int>& nums, vector<int>& multi) {
        int n=nums.size();
        int m=multi.size();
                
        vector<vector<int>> dp(m+1, vector<int>(m+1, 0));
        
        for(int ind=m-1; ind>=0; ind--)
        {
            for(int l=ind; l>=0; l--)
            {
                int r = n-1-(ind-l);
                
                int a = nums[l]*multi[ind] + dp[l+1][ind+1];
                int b = nums[r]*multi[ind] + dp[l][ind+1];
                
                dp[l][ind]=max(a,b);
            }
        }
        
        return dp[0][0];
    }
};