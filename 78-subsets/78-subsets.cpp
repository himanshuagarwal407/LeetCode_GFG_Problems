class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        
        vector<vector<int>> powerSet;
        
        for(int i=0; i<=((1<<n)-1); i++)
        {
            vector<int> subset;
            
            for(int bit=0; bit<n; bit++)
                if(i & (1<<bit))
                   subset.push_back(nums[bit]);
    
            powerSet.push_back(subset);
        }
        
        return powerSet;
    }
};