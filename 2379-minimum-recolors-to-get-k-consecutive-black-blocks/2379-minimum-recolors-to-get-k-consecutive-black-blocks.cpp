class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int mn = k;
        
        int numW=0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W') numW++;
        }
        mn = min(numW, mn);
        
        for(int i= k;i<n;i++){
            if(blocks[i]=='W')numW++;
            if(blocks[i-k]=='W') numW--;
            
            mn = min(numW,mn);
        }
        return mn;
    }
};