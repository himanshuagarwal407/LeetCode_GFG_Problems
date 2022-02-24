class Solution {
public:
    bool binarySearch(vector<int> v, int x)
    {
        int n=v.size();
        int l=0, h=n-1;
        
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(v[mid]==x)
                return true;
            else if(v[mid]>x)
            {
                h=mid-1;
            }
            else
                l=mid+1;
        }
        
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0; i<n; i++)
        {
            if(target>=matrix[i][0] && target<=matrix[i][m-1])
            {
                if(binarySearch(matrix[i], target))
                    return true;
                else
                    return false;
            }
        }
        
        return false;
    }
};