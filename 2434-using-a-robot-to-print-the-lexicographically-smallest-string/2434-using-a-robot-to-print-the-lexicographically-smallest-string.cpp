class Solution {
private:
    char getNext(vector<int> &cnt){
        for(int i=0;i<26;i++)
            if(cnt[i]!=0) return i+'a';
        return 'A';
    }
public:
    string robotWithString(string s) {
        vector<int> cnt(26,0);
        
        for(auto& c: s)
            cnt[c-'a']++;
        
        stack<char> st;
        string ans="";
        
        for(auto &c:s){
            st.push(c);
            cnt[c-'a']--;
            while(!st.empty()&& st.top()<= getNext(cnt)){
                ans+= st.top();
                st.pop();
            }
        }
        
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }
        
        return ans;
    }
};