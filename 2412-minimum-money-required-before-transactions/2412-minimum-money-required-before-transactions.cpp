class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long sum= 0;
        int mxcb=0, mxcost=0;
        
        for(auto &v: transactions){
            if(v[0]>=v[1]){
                sum+= v[0]-v[1];
                mxcb = max(mxcb, v[1]);
            }
            else{
                mxcost = max(mxcost, v[0]);
            }
        }
        
        return sum+ max(mxcost,mxcb);
    }
};