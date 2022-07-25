class Solution {
public:
    bool solve(vector<int>& cookies, vector<int> &v, int &k,int &mid, int idx){
        if(idx==cookies.size()) return true;
        
        for(int i=0;i<k;i++){
            if(v[i]+cookies[idx]<= mid){
                v[i]+=cookies[idx];
                if(solve(cookies, v, k, mid, idx+1)) return true;
                v[i]-=cookies[idx];
            }
            if(v[i]==0) return false;
        }
        return false;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        
        sort(cookies.begin(), cookies.end());
        
        int l= INT_MIN, sum=0;
        
        for(auto &n :cookies){
            sum+=n;
            l= max(l, n);
        }
        vector<int> v(k);
        int r= sum, ans= sum;
        
        while(l<=r){
            fill(v.begin(), v.end(),0);
            int mid= (l+r)>>1;
            if(solve(cookies, v,k, mid,0)){
                ans= mid;
                r= mid-1;
            }
            else{
                l= mid+1;
            }
        }
        return ans;
    }
};