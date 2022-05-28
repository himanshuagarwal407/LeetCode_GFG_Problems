class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        
        for(int i=0; i<n; i++)
            sum+=nums[i];
        
        int sum1;
        sum1=n*(n+1)/2;
        
        return sum1-sum;
    }
};