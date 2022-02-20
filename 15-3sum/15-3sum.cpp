class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> ans;
        
        if(n<3)
            return ans;
        
        sort(nums.begin(), nums.end());
        
        set<vector<int>> s;
        for(int i=0; i<n-2; i++)
        {
            int val = nums[i];
            int l = i+1;
            int r = n-1;
            
            while(l<r)
            {
                int sum = val + nums[l] + nums[r];
                
                if(sum==0)
                {
                    s.insert({val, nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if(sum<0)
                    l++;
                else
                    r--;
            }
        }
        
        for(auto x:s)
            ans.push_back(x);
        
        return ans;
    }
};