class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        unordered_map<int, char> map;
        for(int i=0;i<26;i++){
            map[i]= i+'a';
        }
        
        int n = s.size();
        vector<long long> str(n+1,0);
        
        for(auto &shift: shifts){
            int start = shift[0];
            int end= shift[1];
            int dir= shift[2];
            
            if(dir==1){
                str[start]++;
                str[end+1]--;
            }
            else{
                str[start]--;
                str[end+1]++;
            }
        }
        for(int i=1;i<str.size();i++)
            str[i]+=str[i-1];
        
        for(int i=0;i<str.size()-1;i++){
            str[i]%=26;
            int temp= (26+ (s[i]-'a')+ str[i])%26;
            s[i]= map[temp];
            
        }
        
            
        return s;
    }
};