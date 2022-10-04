class Solution {
public:
    int minCost(string s, vector<int>& time) {
        int n = s.size();
        
        int sum=0, curr=0, mx, i=0;
        
        while(i<n){
            mx= time[i];
            curr=time[i];
            
            while(i+1<n && s[i]==s[i+1]){
                mx= max(time[i+1], mx);
                curr+= time[i+1];
                ++i;
            }
            
            sum+=(curr-mx);
            ++i;
        }
        
        return sum;
    }
};