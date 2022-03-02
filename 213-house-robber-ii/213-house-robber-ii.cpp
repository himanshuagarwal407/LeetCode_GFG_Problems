class Solution {
public:
    int robLinear(vector<int> nums) {
        int n=nums.size();
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(nums[0]);
        int pmax=0;
        
        for(int i=1; i<n; i++)
        {
            int x=dp.size();
            
            if(nums[i]+pmax > dp[x-1])
            {
                dp.push_back(nums[i]+pmax);
                pmax = max(pmax, dp[x-1]);
            }
            else
            {
                pmax = max(pmax, dp[x-1]);
            }
        }
        
        return dp[dp.size()-1];
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        
        return max(robLinear(vector<int> (nums.begin()+1,nums.end())), robLinear(vector<int> (nums.begin(), nums.end()-1)));
    }
};