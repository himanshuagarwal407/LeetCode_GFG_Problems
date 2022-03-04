class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int mSum=0;
        
        for(int i=0; i<n; i++)
        {
            if(i<=mSum)
                mSum = max(i+nums[i], mSum);
            else
                return false;
        }
        
        return true;
    }
};