#define pb push_back
class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        vector<int> zero, one;
        int n = s.size();
        
        for(int i=0;i<n;i++){
            if(s[i]=='0') zero.pb(i);
            else one.pb(i);
        }
        if(!zero.size() || !one.size()) return 0;
        
        int sz0= zero.size(), sz1= one.size(), cnt=0;
        
        while(zero[0]!= sz1){
            for(int i=0;i<sz0;i++){
                
                if( i + sz1 == zero[i]) break;
                
                int pos= upper_bound(one.begin(), one.end(), zero[i])- one.begin();
                
                if(one[pos]==zero[i]+1){
                    one[pos]--;
                    zero[i]++;
                }
            }
            cnt++;
        }
        return cnt;
    }
};