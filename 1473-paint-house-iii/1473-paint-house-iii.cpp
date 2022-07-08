class Solution {
public:
    const int maxCost = 1000001;
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(target+1, vector<int>(n, maxCost)));
        
        for(int col=1; col<=n; col++)
        {
            if(houses[0]==col)
                dp[0][1][col-1]=0;
            else if(!houses[0])
                dp[0][1][col-1]=cost[0][col-1];
            
        }
        
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<=min(target, i+1); j++)
            {
                for(int k=1; k<=n; k++)
                {
                    if(houses[i] && k!=houses[i])
                        continue;
                    
                    int currCost=maxCost;
                    
                    for(int pk=1; pk<=n; pk++)
                    {
                        if(pk!=k)
                            currCost = min(currCost, dp[i-1][j-1][pk-1]);
                        else
                            currCost = min(currCost, dp[i-1][j][pk-1]);
                            
                    }
                    
                    int cp = houses[i]?0:cost[i][k-1];
                    dp[i][j][k-1]=currCost+cp;
                }
            }
        }
        
        int minCost=maxCost;
        
        for(int col=1; col<=n; col++)
            minCost=min(minCost, dp[m-1][target][col-1]);
        
        return minCost==maxCost?-1:minCost;
        
    }
};