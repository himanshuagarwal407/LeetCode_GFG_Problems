class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        sort(tokens.begin(), tokens.end());
        
        int l=0, r=n-1, score=0, ans=0;
        while(l<=r)
        {
            if(power>=tokens[l])
            {
                power-=tokens[l++];
                score++;
                ans=max(ans, score);
            }
            else if(score>0)
            {
                power+=tokens[r--];
                score--;
                ans=max(ans, score);
            }
            else
                break;
        }
        
        return ans;
    }
};