class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        int mx=0;
        for(auto &inter: intervals)
            mx= max(mx, inter[1]);
        
        vector<int> v(mx+2,0);
        
        for(auto &inter: intervals){
            v[inter[0]]++;
            v[inter[1]+1]--;
        }
        
        for(int i=1;i<mx+2;i++)
            v[i]+=v[i-1];
        
        return *max_element(v.begin(), v.end());
        
    }
};