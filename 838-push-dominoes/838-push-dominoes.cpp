class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> left(n,-1), right(n,-1);
        
        int nright= -1;
        for(int i=0;i<n;i++){
            if(dominoes[i]=='.'){
                if(nright==-1) continue;
                right[i]= i- nright;
            }
            else if(dominoes[i]=='R')
                nright=i;
            else
                nright=-1;
        }
        
        int nleft=-1;
        for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='.'){
                if(nleft==-1) continue;
                left[i]= nleft- i;
            }
            else if(dominoes[i]=='L')
                nleft=i;
            else
                nleft=-1;
        }
        
        for(int i=0;i<n;i++){
            if(dominoes[i]=='.'){
                if(left[i]==-1 && right[i]==-1) continue;
                else if(left[i]==-1 || right[i]==-1)
                    dominoes[i]= (left[i]==-1)?'R': 'L';
                else{
                    if(left[i]>right[i])
                        dominoes[i]= 'R';
                    else if( right[i]>left[i])
                        dominoes[i]='L';
                }
            }
        }
        
        return dominoes;
    }
};