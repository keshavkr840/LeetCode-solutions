class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        
        int cnt=0, n = s.size();
        bool change = true;
        
        while(change){
            change = false;
            for(int i=0;i<n-1;i++){
                if(s[i]=='0' && s[i+1]=='1'){
                    swap(s[i], s[i+1]);
                    change = true;
                    i++;
                }
            }
            cnt+=change;
        }
        return cnt;
    }
};