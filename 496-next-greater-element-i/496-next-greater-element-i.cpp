class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr(nums1.size(),-1);
        
        for(int i=0; i<nums1.size(); i++)
        {
            int x=nums1[i];
            bool flag=false;
            for(int j=0; j<nums2.size(); j++)
            {
                if(nums2[j]==x )
                    flag=true;
                if(flag==true && nums2[j]>x)
                {
                    arr[i]=nums2[j];
                    break;
                }
            }
            
        }
        
        return arr;
    }
};