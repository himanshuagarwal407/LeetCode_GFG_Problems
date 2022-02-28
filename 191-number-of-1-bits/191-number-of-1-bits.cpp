class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n)
        {
            int m=n%2;
            if(m==1)
                count++;
            n=n/2;
        }
        
        return count;
    }
};