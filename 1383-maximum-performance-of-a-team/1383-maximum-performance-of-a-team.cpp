class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long ans=0, sum=0;
        int mod=1e9+7;
        
        vector<pair<int, int>> v(n);
        for(int i=0;i<n;i++){
            v[i]= make_pair(efficiency[i], speed[i]);
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto &[e,s]: v){
            
            sum+=s;
            pq.push(s);
            
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
                
            }
                
            
            ans= max(ans, sum*e);
        }
        return ans%mod;
    }
};