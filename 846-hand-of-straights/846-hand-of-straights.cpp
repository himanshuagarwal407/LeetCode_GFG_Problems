class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        int n=hand.size();
        
        if(gs==1)
            return true;
        if(n%gs!=0)
            return false;
        
        sort(hand.begin(), hand.end());
        vector<priority_queue<int>> v(n/gs);
        
        int i=0;
        for(int k=0; k<n; k++)
        {
            int x=hand[k];
            int j=i;
            while((v[j].size()!=0 && v[j].top()!=(x-1)) || v[j].size()==gs)
            {
                j++;
                if(j==(n/gs))
                    return false;
            }
            v[j].push(x);
            
            if(v[j].size()==gs)
                i++;
        }
        
        return true;
    }
};