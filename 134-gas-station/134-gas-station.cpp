class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        for(int i=0;i<n;i++){
            gas[i]-=cost[i];
        }
        int total= accumulate(gas.begin(), gas.end(),0);
        if(total<0) return -1;
        
        int start=0, sum=0;
        
        for(int i=0;i<n;i++){
            sum+=gas[i];
            if(sum<0){
                start= i+1;
                sum=0;
            }
        }
        
        return start;
    }
};