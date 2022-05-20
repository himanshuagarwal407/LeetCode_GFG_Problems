class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        
        int index=1;
        
        for(int i=1; i<n; i++)
        {
            if(nums[index-1]!=nums[i])
            {
                nums[index]=nums[i];
                index++;
            }
        }
        
        return index;
    }
};