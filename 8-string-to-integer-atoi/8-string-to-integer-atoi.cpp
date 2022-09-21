class Solution {
public:
    long long mx= pow(2,31)-1, mn = -1*pow(2,31);
    int myAtoi(string s) {
        int n = s.size();
        bool pos=true, vis= false;
        long long ans=0;
        
        for(auto &c: s){
            if(c==' '){
                if(vis) break;
                continue;
            }
            if(c=='-' || c=='+'){
                if(vis) break;
                pos= (c=='+');
                vis=true;
                continue;
            } 
            if(c>='0'  && c<='9'){
                ans= ans*10 +(c-'0');
                if(ans>mx || ans<mn) break;
            }
            else break;
            
            
            vis = true;
                
        }
        if(!pos)
            ans=-1* ans;
        if(ans>mx) return mx;
        if(ans<mn) return mn;
        
        return ans;
    }
};