class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, h= nums.size()-1;
        if(h==0 || nums[h]> nums[l]) return nums[0];
        
        while(l<h){
            int mid = (l+h)/2;
            
            if(nums[mid] > nums[mid+1]) return nums[mid+1];
            
            else if (nums[mid] > nums[l]) l= mid+1;
            else h= mid;
        }
        return -1;
    }
};