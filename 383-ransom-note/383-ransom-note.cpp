class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n=ransomNote.size();
        int m=magazine.size();
        
        unordered_map<char, int> a;
        unordered_map<char, int> b;
        
        for(int i=0; i<m; i++)
        {
            char c=magazine[i];
            if(a.find(c)==a.end())
                a.insert({c, 0});
            else
                a[c]++;
        }
        
        for(int i=0; i<n; i++)
        {
            int c=ransomNote[i];
            if(a.find(c)==a.end())
                return false;
            else
            {
                if(a[c]==-1)
                    return false;
                else
                    a[c]--;
            }
        }
        
        return true;
    }
};