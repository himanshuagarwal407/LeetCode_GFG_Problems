class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        
        if(n==3)
            return nums[0]+nums[1]+nums[2];
        
        int minDiff=INT_MAX;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++)
        {
            int val = nums[i];
            int l=i+1, h=n-1;
            
            while(l<h)
            {
                int sum = val+nums[l]+nums[h];
                int diff = target-sum;
                
                if(sum==target)
                    return target;
                
                minDiff = (abs(minDiff)>abs(diff))?diff:minDiff;
                
                if(sum<target)
                    l++;
                else
                    h--;
            }
        }
        
        return target-minDiff;
    }
};