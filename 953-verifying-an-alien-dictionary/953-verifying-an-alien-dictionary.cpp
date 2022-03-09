class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        int n=order.size();
        map<char, int> map;
        
        int k=0;
        for(int i=0; i<n; i++)
        {
            map[order[i]]=k;
            k++;
        }
        
        bool res=true;
        for(int j=0; j<words.size()-1; j++)
        {
            string w1=words[j];
            string w2=words[j+1];
        
            int n1=w1.size();
            int n2=w2.size();
            
            for(int i=0; i<n1; i++)
            {
                if(i==n2)
                    return false;
                if(w1[i]==w2[i])
                    continue;
                else
                {
                    if(map[w1[i]]<map[w2[i]])
                        break;
                    else 
                        return false;
                }
            }
        }
        
        return true;
    }
};