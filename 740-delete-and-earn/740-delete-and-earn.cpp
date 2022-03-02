class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        
        int map[10001]={0};
        for(int i=0; i<n; i++)
            map[nums[i]]++;
        
        vector<int> dp(10003);
        dp[0]=0;
        dp[1]=map[0]*0;
        
        for(int i=2; i<=10001; i++)
            dp[i] = max( map[i-1]*(i-1) + dp[i-2], dp[i-1]);
        
        return dp[10001];
    }
};