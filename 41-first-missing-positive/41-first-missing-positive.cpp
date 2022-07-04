class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]<=0 || nums[i]>n)
                nums[i]= n+1;
        }
        
        for(int i=0;i<n;i++){
            if(abs(nums[i])!= n+1){
                if(nums[abs(nums[i])-1]>0)
                    nums[abs(nums[i])-1]*=-1;
            }
        }
        
        int i=0;
        for(i;i<n;i++){
            if(nums[i]>0)
                break;
        }
        return i+1;
    }
};