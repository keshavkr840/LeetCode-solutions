class Solution {
public:
    int dp[100001][3];
    
    bool isValid(vector<int>& nums, int i, int len){
        
        if(i==nums.size()){
            if(len==0) return dp[i][len]= true;
            if(len==1) return dp[i][len] = false;
            else{
                if(nums[i-1]==nums[i-2]) return dp[i][len]= true;
                else return dp[i][len]= false;
            }
        }
        
        if(dp[i][len]!=-1) return dp[i][len];
        
        if(len==0)
            return dp[i][len]= isValid(nums, i+1, 1);
        
        if(len==1){
            if(nums[i]==nums[i-1]){
                return dp[i][len]= isValid(nums,i+1, 0) || isValid(nums, i+1, 2);
            }
            if(nums[i]-nums[i-1]==1){
                return dp[i][len]= isValid(nums, i+1, 2);
            }
            else return dp[i][len]=  false;
        }
        
        if(len==2){
            if(nums[i-1]==nums[i-2]){
                if(nums[i]==nums[i-1]) return dp[i][len]= isValid(nums, i+1,0);
                else return dp[i][len]= false;
            } 
            if(nums[i-1]== 1+ nums[i-2]){
                if(nums[i]==1+ nums[i-1]) return dp[i][len]= isValid(nums, i+1, 0);
                else return dp[i][len]=  false;
            }
        }
        return dp[i][len] = false;
    }
    bool validPartition(vector<int>& nums) {
        memset(dp,-1, sizeof(dp));
        return isValid(nums, 0, 0);
    }
};