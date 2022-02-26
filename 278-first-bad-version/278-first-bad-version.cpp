// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1,i=-1;
        
        while(l<=n)
        {
            int mid=l+(n-l)/2;
            
            if(isBadVersion(mid)==false)
                l=mid+1;
            else
            {
                n=mid-1;
                i=mid;
            }
        }
        
        return i;
    }
};