class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int oneback=cost[0];
        int twoback = 0;
        
        int curr;
        
        for(int i=1;i<n;i++){
            curr = cost[i]+ min(oneback, twoback);
            twoback = oneback;
            oneback = curr;
        }
        return min(twoback, oneback);
        
    }
};