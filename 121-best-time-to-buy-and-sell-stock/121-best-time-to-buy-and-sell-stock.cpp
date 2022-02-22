class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int min=INT_MAX, max=INT_MIN;
        int minIndex=-1, maxIndex=-1;
        int profit=0;
        
        for(int i=0; i<n; i++)
        {
            if(prices[i]>max)
            {
                max=prices[i];
                maxIndex=i;
                if(profit<(max-min))
                    profit=max-min;
            }
            if(prices[i]<min)
            {
                min=prices[i];
                minIndex=i;
            }
            if(maxIndex<=minIndex)
            {
                maxIndex=-1;
                max=INT_MIN;
            }
        }
        
        // if(maxIndex==-1)
        //     return 0;
        // return max-min;
        return profit;
        
    }
};