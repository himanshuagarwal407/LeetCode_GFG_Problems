class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k=0, i=0, j=0;
        
        while(j<n && i<m+k)
        {
            if(nums1[i]>nums2[j])
            {
                nums1.insert(nums1.begin()+i, nums2[j]);
                j++;
                i++;
                k++;
                nums1.pop_back();
            }
            else
                i++;
        }
        while(j<n)
        {
            nums1.insert(nums1.begin()+i,nums2[j]);
            i++;
            j++;
            nums1.pop_back();
        }
    }
};