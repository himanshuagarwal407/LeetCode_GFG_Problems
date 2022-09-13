class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n=data.size();
        
        int m1=1<<7;
        int m2=1<<6;
        
        int c=0;
        
        for(int i=0; i<n; i++)
        {
            if(c==0)
            {
                int m=1<<7;
                while((m&data[i])!=0)
                {
                    c++;
                    m=m>>1;
                }
                if(c==0)
                    continue;
                if(c>4 || c==1)
                    return false;
            }
            else
            {
                if(!(((data[i]&m1)!=0) && ((data[i]&m2)==0)))
                    return false;
            }
            
            c--;
        }
        
        return c==0;
    }
};