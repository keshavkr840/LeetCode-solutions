class Solution {
public:
    int minimumNumbers(int num, int k) {
        if((1 & num) && !(k&1))
            return -1;
        if(k==0 && num%10!=0) return -1;
        
        if(num==0) return 0;
        // if(num%)
        
        int ans=0;
        while(num>=0){
            if(num%10==k) return ans+1;
            ++ans;
            num-=k;
        }
        return -1;
    }
};