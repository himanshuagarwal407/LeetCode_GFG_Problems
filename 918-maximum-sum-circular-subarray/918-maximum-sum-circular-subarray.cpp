class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        
        int maxSum=nums[0], currMax=nums[0], minSum=nums[0], currMin=nums[0], sum=nums[0];
        
        for(int i=1; i<n; i++)
        {
            sum+=nums[i];
            
            currMax=max(currMax+nums[i], nums[i]);
            maxSum=max(maxSum, currMax);
            
            currMin=min(currMin+nums[i], nums[i]);
            minSum=min(currMin, minSum);
            
        }
        
        if(sum==minSum)
            return maxSum;
            
            
        return max(maxSum, sum-minSum);
    }
};