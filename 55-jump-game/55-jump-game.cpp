class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        bool flag = false;
        
        for(int i=1;i<n;i++){
            flag = false;
            for(int j=i-1;j>=0;j--){
                if( (j+nums[j]) >= i) flag = true;
                if(flag) break;
            }
            if(!flag) return false;
        }
        return true;
        
    }
};