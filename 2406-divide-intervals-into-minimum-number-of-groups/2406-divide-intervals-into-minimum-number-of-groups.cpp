class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(), intervals.end());
        
        for(auto &inter: intervals){
            
            if(pq.size()>0 && pq.top()< inter[0])
                pq.pop();
            pq.push(inter[1]);
            
        }
        return pq.size();
        
    }
};