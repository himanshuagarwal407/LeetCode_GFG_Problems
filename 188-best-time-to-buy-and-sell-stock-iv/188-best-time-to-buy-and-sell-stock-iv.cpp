class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(k==0)
            return 0;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<=1; j++)
            {
                for(int l=1; l<=k; l++)
                {
                    if(j)
                        dp[i][j][l] = max(dp[i+1][0][l]-prices[i], dp[i+1][1][l]);
                    else
                        dp[i][j][l] = max(dp[i+1][1][l-1]+prices[i], dp[i+1][0][l]);
                }
            }
        }
        
        return dp[0][1][k];
    }
};