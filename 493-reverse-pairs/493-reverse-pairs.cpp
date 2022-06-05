class Solution {
    int count=0;
public:
    void merge(vector<int>& nums, int left, int mid, int right)
    {
        int i=left;
        int j=mid+1;
        
        while(i<=mid && j<=right)
        {
            if(nums[i] > 2*(long long)nums[j])
            {
                // cout << nums[i] << " " << nums[j] << endl;
                count += mid-i+1;
                j++;
            }
            else
                i++;
        }
        
        i=left, j=mid+1;
        int k=0;
        
        vector<int> v(right-left+1);
        
        while(i<=mid && j<=right)
        {
            if(nums[i]<nums[j])
                v[k++]=nums[i++];
            else
                v[k++]=nums[j++];
        }
        while(i<=mid)
            v[k++]=nums[i++];
        while(j<=right)
            v[k++]=nums[j++];
        
        k=0;
        for(int i=left; i<=right; i++)
            nums[i]=v[k++];
        
    }
    
    void mergeSort(vector<int>& nums, int left, int right)
    {
        if(left < right)
        {
            int mid = left + (right-left)/2;
            
            mergeSort(nums, left, mid);
            mergeSort(nums, mid+1, right);
            
            merge(nums, left, mid, right);
        }
    }
    
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        
        mergeSort(nums, 0, n-1);
        
        return count;
    }
};