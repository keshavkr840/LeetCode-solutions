class Solution {
public:
    string pushDominoes(string s) {
        int n = s.size(), right=-1;
        
        for(int i=0;i<n;i++){
            
            if(s[i]!='.'){
                
                if(s[i]=='L'){
                    if(right==-1){
                        for(int j=i-1;j>=0 && s[j]=='.'; j--)
                            s[j]='L';
                    }
                    else{
                        for(int r=right+1, j= i-1;r<j; r++, j--)
                            s[r]='R', s[j]='L';
                    }
                    
                    right=-1;
                }
                
                else{
                    if(right!=-1){
                        for(int r=right+1; r<i; r++)
                            s[r]='R';
                    }
                    right=i;
                }
            }
            
        }
        if(right!=-1)
            for(int r=right+1; r<n;r++)
                s[r]='R';
        
        return s;
    }
};