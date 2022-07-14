class Solution {
private:
    bool isPalindrome(string &s, int i, int j){
        while(i<j)
            if(s[i++]!=s[j--]) return false;
        return true;
    }
    void solve(string &s, vector<vector<string>>& ans, vector<string> &temp, int &n, int idx){
        if(idx==n){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<n;i++){
            string str= s.substr(idx,(i-idx+1));
            if(isPalindrome(s,idx,i))
            {
                temp.push_back(str);
                solve(s,ans, temp, n,i+1);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        int n = s.length();
        
        solve(s,ans, temp, n, 0);
        return ans;
    }
};