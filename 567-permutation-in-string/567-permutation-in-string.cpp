class Solution {
public:
    bool equalFre(vector<int> v1, vector<int> v2)
    {
        for(int i=0; i<26; i++)
            if(v1[i]!=v2[i])
                return false;
        
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int n=s1.size(), m=s2.size();
        
        if(n>m)
            return false;
        
        vector<int> freS1(26,0);
        vector<int> freS2(26,0);
        
        for(char c:s1)
            freS1[c-'a']++;
        
        int i=0, j=0;
        
        while(j<m)
        {
            freS2[s2[j]-'a']++;
            
            if(j-i+1 == n)
                if(equalFre(freS1, freS2))
                    return true;
            
            if(j-i+1 < n)
                j++;
            else
            {
                freS2[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        
        return false;
    }
};