class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]) return a[1]> b[1];
        else return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int sz= intervals.size();
        if(sz==1) return intervals;
        
        sort(intervals.begin(), intervals.end(), comp);
//         for(auto &v: intervals){
//             cout<<v[0]<<", "<<v[1]<<endl;
//         }
        
        vector<vector<int>> ans;
        
        int l=0, mx= intervals[0].back();
        
        for(int i=1;i<sz;i++){
            if( mx < intervals[i].front()){
                ans.push_back({intervals[l].front(), mx});
                mx= intervals[i].back();
                l=i;
            }
            else{
                mx= max(mx, intervals[i].back());
            }
        }
        ans.push_back({intervals[l].front(), mx});
        return ans;
    }
};