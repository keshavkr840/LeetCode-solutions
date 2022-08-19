class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> ans;
        int n = s.size();
        
        int j=0;
        for(int i=0;i<=n;i++){
            ans.push_back(i);
            if(i==n || s[i]=='I'){
                reverse(ans.begin() +j, ans.end());
                j=i+1;
            }
        }
        return ans;
    }
};