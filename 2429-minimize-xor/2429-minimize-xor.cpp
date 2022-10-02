class Solution {
public:
    int minimizeXor(int a, int b) {
        int n1= __builtin_popcount(a);
        int n2= __builtin_popcount(b);
        
        if(n1==n2) return a;
        
        if(n2> n1){
            int ans= a;
            int bits=n2-n1;
            
            for(int i=0;i<32;i++){
                if(bits==0) return ans;
                
                if((ans & (1<<i)) ==0){
                    ans= ans|(1<<i);
                    bits--;
                }
            }
        }
        
        if(n1>n2){
            int ans=0;
            int bits= n2;
            for(int i=31; i>=0;i--){
                if(bits==0) return ans;
                
                if(a &(1<<i)){
                    ans= ans| (1<<i);
                    bits--;
                }
            }
        }
        
        return -1;
    }
};