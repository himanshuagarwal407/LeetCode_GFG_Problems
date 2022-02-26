class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        
        if(nums[n-1]<target)
            return n;
        if(nums[0]>target)
            return 0;
        int index = 0;
        int l=0, h=n-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target){
                h=mid-1;
                index = mid;}
            else{
                l=mid+1;
                index = mid+1;}
        }
        
        return index;
    }
};