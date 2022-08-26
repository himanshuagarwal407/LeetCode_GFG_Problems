class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        sort(s.begin(), s.end());
        
        vector<string> power;
        for(int i=0; i<=30; i++)
        {
            int p=pow(2, i);
            power.push_back(to_string(p));
            sort(power[i].begin(), power[i].end());
            
            if(s==power[i])
                return true;
        }
            
        return false;
    }
};