class Solution {
public:
    vector<string> permutation;
    
    void permute(string s, int index)
    {
        if(index==s.size())
        {
            permutation.push_back(s);
            return;
        }
        
        if(s[index]>=97 && s[index]<=122)
        {
            s[index] -= 32;
            permute(s, index+1);
            s[index] += 32;
        }
        else if(s[index]>=65 && s[index]<=90)
        {
            s[index] += 32;
            permute(s, index+1);
            s[index] -= 32;
        }
        
        permute(s, index+1);
    }
    
    vector<string> letterCasePermutation(string s) {
        permute(s, 0);
        
        return permutation;
    }
};