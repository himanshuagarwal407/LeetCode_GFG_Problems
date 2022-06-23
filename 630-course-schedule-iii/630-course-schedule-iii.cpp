class Solution {
public:
    static bool cmpr(const vector<int>& v1, const vector<int>& v2)
    {
        return v1[1]<v2[1];
    }
    
    int scheduleCourse(vector<vector<int>>& cour) {
        int n=cour.size();
        
        sort(cour.begin(), cour.end(), cmpr);
        
        // for(int i=0; i<n; i++)
        // {
        //     cout << cour[i][0] << " " << cour[i][1] << endl;
        // }
        
        int t=0, count=0;
        for(int i=0; i<n; i++)
        {
            if(cour[i][1]<cour[i][0])
                continue;
             if( ( t + cour[i][0] ) <= cour[i][1])
             {
                 t+=cour[i][0];
                 cour[count++] = cour[i];
             }
            else
            {
                int maxI = i;
                for(int j=0; j<count; j++)
                {
                    if(cour[j][0] > cour[maxI][0])
                        maxI=j;
                }
                if(cour[maxI][0]>cour[i][0])
                {
                    t+= (cour[i][0]-cour[maxI][0]);
                    cour[maxI]=cour[i];
                }
                
                // cour[maxI][0]=-1;
            }
        }
        
        return count;
    }
};