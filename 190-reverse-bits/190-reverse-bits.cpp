class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans=0;
        int bit = (n&1)?1:0;
        
        for(int i=0; i<32; i++)
        {
            ans = (ans<<1)|bit;
            n = n>>1;
            bit = (n&1)?1:0;
        }
        
        return ans;
    }
};