class Solution {
    public boolean increasingTriplet(int[] nums) {
        int c1= Integer.MAX_VALUE, c2= Integer.MAX_VALUE;
        int n = nums.length;
        
        for(int i=0;i<n ;i++){
            if(nums[i]<= c1)
                c1= nums[i];
            else if(nums[i]<=c2)
                c2= nums[i];
            else
                return true;
        }
        
        return false;
    }
}