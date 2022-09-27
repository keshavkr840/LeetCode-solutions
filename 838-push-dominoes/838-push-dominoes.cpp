class Solution {
public:
    string pushDominoes(string s) {
        int n = s.size();
        int l=0, r=-1;
        
        for(int i=0;i<n;i++){
            
            if(s[i]=='L'){
                if(r==-1){
                    int j= i-1;
                    while(j>=0 && s[j]=='.')
                        s[j--]='L';
                }
                else{
                    for(int j=r+1, k=i-1;j<k ; j++, k--)
                        s[j]='R', s[k]='L';
                    r=-1;
                }
            }
            else if(s[i]=='R'){
                if(r!=-1)
                    for(int j=r+1;j<i;j++)
                        s[j]='R';
                
                r=i;
                    
            }
        }
        
        if(r!=-1){
            for(int j=r+1; j< n; j++)
                s[j]='R';
        }
        return s;
    }
};