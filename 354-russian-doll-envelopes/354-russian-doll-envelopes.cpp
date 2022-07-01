class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();
        vector<int> ans;
        
        sort(env.begin(),env.end(),[&](vector<int>&a, vector<int>&b){
           if(a[0]==b[0]) return a[1]>b[1];
            else return a[0]<b[0];
        });
        
        
        for(int i=0;i<n;i++){
            auto it = lower_bound(ans.begin(),ans.end(),env[i][1]);
            if(it==ans.end())
                ans.push_back(env[i][1]);
            else
                *it = env[i][1];
            // for(auto &v: ans)
            //     cout<<"("<<v[0]<<","<<v[1]<<"), ";
            // cout<<endl;
        }
        return ans.size();
    }
};