class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans=0;
        int l=0, n =s.length();
        
        for(int i=1;i<n;i++){
            if(s[i]-s[i-1]!=1){
                ans= max(ans, i-l);
                l=i;
            }
        }
        ans= max( ans, n-l);
        return ans;
    }
};