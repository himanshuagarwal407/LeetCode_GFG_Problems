class Solution {
public:
    void situation(vector<int>& c, int t, vector<int> curr, int currPos, vector<vector<int>>& ans)
    {
        if(t==0)
        {
            ans.push_back(curr);
            return;
        }
//         if(currSum>t)
//             return;
//         if(currSum==t)
//         {
//             ans.push_back(curr);
//             return;
//         }
        
//         for(int i=currPos; i<c.size(); i++)
//         {
//             currSum += c[i];
//             curr.push_back(c[i]);
//             situation(c, t, curr, currSum, i+1, ans);
//             curr.pop_back();
//             currSum -= c[i];
//         }
        for(int i=currPos; i<c.size(); i++)
        {
            if(i>currPos && c[i]==c[i-1])
                continue;
            if(c[i]>t)
                return;
            curr.push_back(c[i]);
            situation(c, t-c[i], curr, i+1, ans);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        
        sort(candidates.begin(), candidates.end());
        situation(candidates, target, curr, 0, ans);
        
        return ans;
    }
};