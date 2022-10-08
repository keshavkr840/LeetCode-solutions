class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, n= nums.size() ;
        int curr=0, len=n+1;
        
        for(int i=0;i<n ;i++){
            curr+= nums[i];
            while(curr>=target){
                len=min(len,i-l+1);
                curr-= nums[l++];
            }
        }
        return (len==n+1)? 0: len;
    }
};