class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        
        int prevDiff=(nums[1]-nums[0]);
        int cnt = (prevDiff!=0)? 2:1;
        
        int diff;
        for(int i=2;i<n;i++){
            diff= nums[i]- nums[i-1];
            if((prevDiff>=0 && diff<0) || (prevDiff<=0 && diff>0)){
                ++cnt;
                prevDiff= diff;
            }
        }
        return cnt;
    }
};