class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        
        int maxPro=nums[0], currMax=nums[0], currMin=nums[0];
        
        
        for(int i=1;  i<n; i++)
        {
            if(currMax==0)
            {
                currMax=nums[i];
                currMin=nums[i];
            }
            else
            {
                int pMin=currMin, pMax=currMax;
                
                currMax=max(max(nums[i], pMax*nums[i]), pMin*nums[i]);
                currMin=min(min(nums[i], pMax*nums[i]), pMin*nums[i]);
            }
            
            maxPro=max(maxPro, currMax);
        }
        
        return maxPro;
    }
};