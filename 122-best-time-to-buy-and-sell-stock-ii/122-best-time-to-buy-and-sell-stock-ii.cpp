class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currP=0;
        int maxP=0;
        int n=prices.size();
        
        for(int i=1; i<n; i++)
        {
            if(prices[i]>prices[i-1])
            {
                currP += prices[i]-prices[i-1];
            }
            
            maxP = max(maxP, currP);
        }
        
        return maxP;
    }
};