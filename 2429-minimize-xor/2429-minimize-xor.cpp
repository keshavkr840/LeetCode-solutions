class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int a = __builtin_popcount(num1);
        int b = __builtin_popcount(num2);
        
        if(a==b) return num1;
        
        if(a>b){
            int ans= num1;
            int bits= a-b;
            
            for(int i=0;i<32; i++){
                if(bits==0) return ans;
                
                if(ans &(1<<i)){
                    ans= ans^(1<<i);
                    bits--;
                }
            }
        }
        
        else{
            int ans= num1;
            int bits= b-a;
            
            for(int i=0;i<32; i++){
                if(bits==0) return ans;
                
                if((ans &(1<<i))==0){
                    ans= ans| (1<<i);
                    bits--;
                }
            }
        }
        return -1;
    }
};