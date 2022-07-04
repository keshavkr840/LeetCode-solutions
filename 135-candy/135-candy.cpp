class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        //O(N) TC & O(1) SC one pass code
        
        int up=0, down=0, peak=0, ans=1;
        
        for(int i=1;i<n;i++){
            if(ratings[i]> ratings[i-1]){
                up++;
                down=0;
                peak= up;
                ans+=1+ up;
            }
            else if(ratings[i]== ratings[i-1]){
                peak=up=down=0;
                ans+=1;
            }
            else{
                up=0;
                ++down;
                ans+=down;
                
                if(peak<down) ans+=1;
            }
        }
        
        return ans;
    }
};