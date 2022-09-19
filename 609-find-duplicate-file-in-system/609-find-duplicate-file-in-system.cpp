class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        int n=paths.size();
        
        vector<vector<string>> ans;
        map<string, vector<string>> mp;
        
        for(int i=0; i<n; i++)
        {
            string s=paths[i];
            int a = s.find('(');
            int sp = s.find(' ');
            string dir = s.substr(0, sp);
            
            while(a!=-1)
            {
                int b = s.find(')', a+1);
                string fi = s.substr(sp+1, a-sp-1);
                string pa = dir+"/"+fi;
                
                string st = s.substr(a+1, b-a-1);
                
                mp[st].push_back(pa);
                
                a=s.find('(', b+1);
                sp=b+1;
            }
        }
        
        for(auto x:mp)
            if(x.second.size()>1)
                ans.push_back(x.second);
        
        return ans;
    }
};