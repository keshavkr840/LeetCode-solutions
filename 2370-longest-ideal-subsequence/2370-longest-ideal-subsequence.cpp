class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26,0);
        int lo, hi;
        for(auto &ch : s){
            int i= ch-'a';
            
            lo= max(0, i-k);
            hi= min(25, i+k);
            
            int mx=0;
            for(;lo<=hi;lo++){
                mx= max(mx, dp[lo]);
            }
            dp[i]= 1+ mx;
        }
        return *max_element(dp.begin(), dp.end());
    }
};