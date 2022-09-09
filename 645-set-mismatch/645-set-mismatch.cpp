class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size(), xor0=0;
        
        for(int i=0; i<n; i++)
            xor0 ^= nums[i];
        for(int i=1; i<=n; i++)
            xor0 ^= i;
        
        int rightBit = xor0 & ~(xor0-1);
        
        int xor1=0, xor2=0;
        for(auto x:nums)
        {
            if((x&rightBit)!=0)
                xor1 ^= x;
            else
                xor2 ^= x;
        }
        
        for(int i=1; i<=n; i++)
        {
            if((i&rightBit)!=0)
                xor1 ^= i;
            else
                xor2 ^= i;
        }
        
        
        for(int i=0; i<n; i++)
            if(nums[i]==xor1)
                return {xor1, xor2};
        
        return {xor2, xor1};
    }
};