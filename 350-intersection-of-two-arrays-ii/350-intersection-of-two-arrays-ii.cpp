class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> ans;
        
        for(int i=0; i<n; i++)
        {
            int x=nums1[i];
            if(find(nums2.begin(), nums2.end(), x) != nums2.end())
            {
                auto it = find(nums2.begin(), nums2.end(), x);
                nums2.erase(it);
                ans.push_back(x);
            }
        }
        
        return ans;
    }
};