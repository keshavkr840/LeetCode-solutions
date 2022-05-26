class Solution {
public:
    int longestValidParentheses(string x) {
        int n = x.size();
        // if(n==0) return 0;
        stack<pair<char,int>> st;
        
        for(int i=0;i<n;i++){
            
            if(st.empty()) st.push({x[i],i});
            // else if(x[i]=='(') st.push({x[i],i});
            else if(st.top().first =='(' && x[i]==')') st.pop();
            else st.push({x[i],i});
        }
        if(st.empty()) return n;
        
        while(!st.empty()){
            int pos= st.top().second;
            st.pop();
            x[pos]='0';
        }
        
        int len=0,mx=0;
        
        for(int i=0;i<n;i++){
            if(x[i]=='0')len=0;
            else len++;
            mx = max(len,mx);
        }
        return mx;
        
    }
};

