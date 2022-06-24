class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum=0;
        
        for(auto x:target)
        {
            pq.push(x);
            sum+=x;
        }
        
        while(pq.top()!=1)
        {
            sum -= pq.top();
            
            if(sum==0 || sum>=pq.top())
                return false;
            
            int prev = pq.top()%sum;
            
            if(sum!=1 && prev==0)
                return false;
            
            pq.pop();
            pq.push(prev);
            
            sum += prev;
        }
        
        return true;
    }
};