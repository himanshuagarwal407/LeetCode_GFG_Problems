class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=0; i<n-1; i++)
        {
            int minp=i;
            for(int j=i+1; j<n; j++)
            {
                if(nums[j]<nums[minp])
                    minp=j;
            }
            
            swap(nums[i], nums[minp]);
        }
    }
};