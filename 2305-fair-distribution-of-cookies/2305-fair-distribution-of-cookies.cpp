class Solution {
private:
    int mx= INT_MAX;
    void solve(vector<int> &cookies, vector<int> &kSum, int i){
        if(i==cookies.size()){
            int currmx= *max_element(kSum.begin(), kSum.end());
            mx= min(mx, currmx);
            return;
        }
        
        for(int p=0;p<kSum.size();p++){
            kSum[p]+=cookies[i];
            solve(cookies, kSum,i+1);
            kSum[p]-= cookies[i];
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> kSum(k,0);
        
        solve(cookies, kSum, 0);
        return mx;
    }
};