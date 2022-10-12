class Solution {
    public int largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        
        int sum=0;
        sum= nums[n-2]+ nums[n-1];
        for(int i=n-2;i>0;i--){
            sum+= nums[i-1];
            
            if(nums[i-1]+ nums[i]> nums[i+1])
                return sum;
            else
                sum-= nums[i+1];
        }
        return 0;
    }
}