class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        stack<int> s;
        string ans="";
        
        for(int i=0;i<=n;i++){
            s.push(i);
            
            if(i==n || pattern[i]=='I'){
                while(!s.empty()){
                    ans+='1'+ s.top();
                    s.pop();
                }
            }
        }
        return ans;
    }
};