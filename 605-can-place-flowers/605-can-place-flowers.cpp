class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        int sz = flowerbed.size();
        if(sz==1 && flowerbed[0]==0) return (--n==0);

        for(int i=0;i<sz;i++){
            
            if(i==0){
                if(flowerbed[0]==0 && flowerbed[1]==0){
                    flowerbed[0]=1;
                    --n;
                }
            }
            else if(i==(sz-1)){
                if(flowerbed[i]==0 && flowerbed[i-1]==0){
                    flowerbed[i]=1;
                    --n;
                }
            }
            else{
                if(flowerbed[i-1]==0 && flowerbed[i]==0 && flowerbed[i+1]==0){
                    flowerbed[i]=1;
                    --n;
                }
            }
            
            if(n==0) break;
            
//             switch(i){
//                 case 0 : if(flowerbed[0]==0 && flowerbed[1]==0){
//                     flowerbed[0]=1;
//                     --n;
//                 }break;
//                 case sz-1: if(flowerbed[i]==0 && flowerbed[i-1]==0){
//                     flowerbed[i]=1;
//                     --n;
//                 }break;
                
//                 default : if(flowerbed[i-1]==0 && flowerbed[i]==0 && flowerbed[i+1]==0){
//                     flowerbed[i]=1;
//                     --n;
//                 }
//             }
//             if(n==0) break;
        }
        
        return (n==0);
    }
};