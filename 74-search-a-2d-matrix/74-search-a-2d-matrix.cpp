class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0; i<n; i++)
        {
            if(target>=matrix[i][0] && target<=matrix[i][m-1])
            {
                vector<int> v=matrix[i];
                int l=0, h=m-1;
        
                while(l<=h)
                {
                    int mid=(l+h)/2;
                    if(v[mid]==target)
                        return true;
                    else if(v[mid]>target)
                    {
                        h=mid-1;
                    }
                    else
                        l=mid+1;
                }
        
                return false;
            }
        }
        
        return false;
    }
};