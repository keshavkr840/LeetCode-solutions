class Solution {
private:
    int mergesort(vector<int>& nums, int start, int end){
        int total = 0;
        if(start<end){
            int mid= start + ((end-start)>>1);
            total+= mergesort(nums, start, mid) + mergesort(nums, mid+1, end) 
                    + invCount(nums,start, mid, end);
        }
        return total;
    }
    int invCount(vector<int> &nums, int start, int mid, int end){
        if(start>=end) return 0;
        // vector<int> temp;
        int count =0;
        int i= start, j= mid+1;
        
        while(i<=mid && j<= end){
            if(nums[i]>  2*(long long)nums[j]){
                j++;
                count+= mid-i+1;
            }
                
            else i++;
        }
        sort(nums.begin()+ start, nums.begin()+ end+1);
        
        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};