class Solution {
private:
    unordered_map<string, bool> map;
public:
    bool solve(string a, string b){
        if(a.size()!= b.size()) return false;
        if(a.compare(b)==0) return true;
        if(a.length()<=1) return false;
        
        string key = a+" "+ b;
        if(map.find(key)!= map.end()) return map[key];
        
        int n = a.length();
        for(int i=1;i<n;i++){
            bool noswap= solve(a.substr(0,i), b.substr(0,i)) && solve(a.substr(i), b.substr(i));
            if(noswap) return true;
            
            bool swap= solve(a.substr(0,i),b.substr(n-i)) && solve(a.substr(i), b.substr(0, n-i));
            if(swap) return true;
        }
        return map[key]= false;
    }
    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length()) return false;
        return solve(s1,s2);
    }
};
