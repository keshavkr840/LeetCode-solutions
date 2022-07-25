class Solution {
private:
    int ans= INT_MAX;
    
    void solve(vector<int> & cookies, int &k, vector<int> &v, int idx){
        
        if(idx==cookies.size()) {
            int tempans= *max_element(v.begin(), v.end());
            ans= min(ans, tempans);
            return;
        }
        
        for(int i=0;i<k;i++){
            v[i]+= cookies[idx];
            solve(cookies, k, v, idx+1);
            v[i]-=cookies[idx];
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> v(k,0);
        
        solve(cookies, k, v, 0);
        return ans;
    }
};