class Solution {
public:
    void permute(vector<int>& nums, vector<vector<int>>& res, int index)
    {
        if(index==nums.size())
            res.push_back(nums);
        
        for(int i=index; i<nums.size(); i++)
        {
            swap(nums[i], nums[index]);
            permute(nums, res, index+1);
            swap(nums[i], nums[index]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        
        permute(nums, res, 0);
        
        return res;
    }
};