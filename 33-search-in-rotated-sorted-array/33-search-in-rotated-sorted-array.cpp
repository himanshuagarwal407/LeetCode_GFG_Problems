class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        
        int l=0, h=n-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            
            if(target==nums[mid])
                return mid;
            else if(nums[mid]>=nums[l])
            {
                if(target>=nums[l] && target<=nums[mid])
                    h=mid-1;
                else
                    l=mid+1;
            }
            else
            {
                if(target>=nums[mid] && target<=nums[h])
                    l=mid+1;
                else
                    h=mid-1;
            }
        }
        
        return -1;
    }
};