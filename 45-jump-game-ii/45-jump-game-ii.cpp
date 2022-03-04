class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, INT_MAX);
        dp[n-1]=0;
        
        for(int ind=n-2; ind>=0; ind--)
        {
            int m=INT_MAX;
            int flag=0;
            
            for(int i=1; i<=nums[ind]; i++)
            {
                if(i+ind >= n-1)
                {
                    dp[ind]=1;
                    flag=1;
                    break;
                }
                else
                {
                    int a=dp[ind+i];
                    if(a!=INT_MAX)
                        m=min(a+1, m);
                }
            }
            
            if(flag==0)
                dp[ind]=m;
        }
        
        return dp[0];
    
    }
};