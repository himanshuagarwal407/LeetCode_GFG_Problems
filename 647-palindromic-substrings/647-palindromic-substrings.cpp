class Solution {
public:
    bool isPalindrom(string s)
    {
        int h=s.size()-1;
        int l=0;
        
        while(l<h)
        {
            if(s[l]!=s[h])
                return false;
            l++;
            h--;
        }
        
        return true;
    }
    
    int countSubstrings(string s) {
        int n=s.size();
        
        int count=0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<=n-i; j++)
            {
                if(isPalindrom(s.substr(i, j)))
                {
                    count++;
                }
            }
        }
        
        return count;
    }
};