class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n=accounts.size();
        int maxW=INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            int wealth=0;
            for(int j=0; j<accounts[i].size(); j++)
                wealth+=accounts[i][j];
            
            maxW = max(maxW, wealth);
        }
        
        return maxW;
    }
};