class Solution {
public:
    vector<vector<int>> ans;
    
    void permutations(vector<int>& nums, int ind)
    {
        int n=nums.size();
        if(ind==n)
            ans.push_back(nums); 
        
        for(int i=ind; i<n; i++)
        {
            swap(nums[ind], nums[i]);
            permutations(nums,ind+1);
            swap(nums[ind], nums[i]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        permutations(nums, 0);
        
        return ans;
    }
};