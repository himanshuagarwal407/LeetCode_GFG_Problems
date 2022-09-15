class Solution {
public:
    vector<int> findOriginalArray(vector<int>& ch) {
        int n=ch.size();
        
        if(n%2==1)
            return {};
        
        sort(ch.begin(), ch.end());
        
        vector<int> ans;
        map<int, int> set;
        
        for(int i=0; i<n; i++)
        {
            int x=ch[i];
            
            if(set.find(x)!=set.end() && x!=0)
            {
                set[x]++;
                continue;
            }
            
            if(x%2==1)
                set[x]=1;
            else
            {
                if(set.find(x/2)==set.end())
                    set[x]=1;
                else
                {
                    set[x/2]--;
                    if(set[x/2]==0)
                        set.erase(x/2);
                    ans.push_back(x/2);
                }
            }
        }
        
        if(set.empty())
            return ans;
        else
            return {};
    }
};