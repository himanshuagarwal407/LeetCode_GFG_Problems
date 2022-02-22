class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        
        if(n<4)
            return ans;
        // if(n==4)
        // {
        //     if(nums[0]>target)
        //         return ans;
        //     if(nums[0]+nums[1]+nums[2]+nums[3] ==  target)
        //     {
        //         ans.push_back({nums[0], nums[1], nums[2],nums[3]});
        //         return ans;
        //     }
        // }
        int mod = 1000000007;
        
        set<vector<int>> s;
        for(int i=0; i<n-3; i++)
        {
            for(int j=i+1; j<n-2; j++)
            {
                int val = (nums[i]+nums[j])%mod;
                int l=j+1, r=n-1;
                
                while(l<r)
                {
                    int sum = ((val+nums[l])%mod+nums[r])%(mod);
    
                    if(sum==target)
                    {
                        s.insert({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                    }
                    else if(sum<target)
                        l++;
                    else
                        r--;
                    
                }
            }
        }
        
        for(auto x:s)
            ans.push_back(x);
        
        return ans;
    }
};