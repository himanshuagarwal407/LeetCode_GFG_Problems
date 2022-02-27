class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int l=0, h=n-1, pos=n-1;
        
        vector<int> ans(n);
        
        while(pos>=0)
        {
            if(abs(nums[l])>abs(nums[h]))
            {
                ans[pos]=nums[l]*nums[l];
                l++;
                pos--;
            }
            else
            {
                ans[pos]=nums[h]*nums[h];
                h--;
                pos--;
            }
        }
        
        return ans;
    }
};