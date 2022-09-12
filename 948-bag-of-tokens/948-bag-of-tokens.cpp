class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int n = tokens.size();
        int score=0, mx=0;
        
        sort(tokens.begin(), tokens.end());
        int l=0,r= n-1;
        
        while(l<=r){
            if(power>=tokens[l]){
                power-= tokens[l++];
                score++;
            }
            else{
                if(score==0) break;
                score--;
                power+=tokens[r--];
                
            }
            mx= max(score, mx);
        }
        return mx;
    }
};