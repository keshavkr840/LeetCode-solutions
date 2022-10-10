class Solution {
public:
    string breakPalindrome(string s) {
        if(s.size()==1)
            return "";
        
        int pos=-1, n = s.size();
        char ch;
        for(int i=0;i<n;i++){
            if(s[i]!='a'){
                ch=s[i];
                pos= i;
                break;
            }
        }
        
        if(pos*2+1 ==n || pos==-1){
            s.pop_back();
            return s+'b';
        }
        else
            s[pos]='a';
        return s;
            
    }
};