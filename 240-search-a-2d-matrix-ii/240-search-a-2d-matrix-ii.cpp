class Solution {
public:
    bool binarySearch(vector<int> arr,  int n, int k)
    {
        int l=0, r=n-1;
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            
            if(arr[mid]==k)
                return true;
            else if(arr[mid]<k)
                l=mid+1;
            else
                r=mid-1;
        }
        
        return false;
    }
        
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0; i<n; i++)
        {
            if(target>=matrix[i][0] && target<=matrix[i][m-1])
                if(binarySearch(matrix[i], m, target))
                    return true;
        }
        
        return false;
    }
};