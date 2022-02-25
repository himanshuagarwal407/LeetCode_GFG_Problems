class Solution {
public:
    void situation(vector<int>& c, int t, vector<int> curr, int currSum, int currPos, vector<vector<int>>& ans)
    {
        if(currSum>t)
            return;
        if(currSum==t)
        {
            ans.push_back(curr);
            return;
        }
        
        for(int i=currPos; i<c.size(); i++)
        {
            currSum += c[i];
            curr.push_back(c[i]);
            situation(c, t, curr, currSum, i, ans);
            curr.pop_back();
            currSum -= c[i];
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> ans;
        vector<int> curr;
        
        situation(c, t, curr, 0, 0, ans);
        
        return ans;
    }
};