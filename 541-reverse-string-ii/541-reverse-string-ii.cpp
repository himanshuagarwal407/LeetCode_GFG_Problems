class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size();
        cout << "n: " << n ;
        if(n==1 || k==0)
            return s;
        
        if(k>n)
        {
            int i=0, j=n-1;
            while(i<j)
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            return s;
        }
        
        for(int l=0; l<n; l+=2*k)
        {
            int i=l, j=l+k-1;
            while(i<j)
            {
                if(j>n)
                    j=n-1;
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        
        return s;
    }
};