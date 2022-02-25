class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0, h=nums.size()-1;
        vector<int> ans(2,-1);
        
        while(l<=h)
        {
            if(nums[l]==target)
                ans[0]=l;
            if(nums[h]==target)
                ans[1]=h;
            if(ans[0]==l && ans[1]==h)
                return ans;
            else if(ans[0]==l)
                h--;
            else if(ans[1]==h)
                l++;
            else
            {
                l++;
                h--;
            }
        }
        
        return ans;
    }
};