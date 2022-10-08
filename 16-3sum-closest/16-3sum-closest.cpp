class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int min_dist= INT_MAX, res=0, n = nums.size();
        
        for(int i=0;i<n; i++){
            int l =i+1, r= n-1;
            
            while(l<r){
                if(abs(target-(nums[i]+ nums[l]+ nums[r])) < min_dist){
                    res= nums[i]+ nums[l]+ nums[r];
                    min_dist= abs(target-res);
                }
                if(nums[i]+ nums[l]+ nums[r]== target)
                    return target;
                else if(nums[i]+ nums[l]+ nums[r]> target)
                    r--;
                else
                    l++;
                
                if(l<r && nums[l]== nums[l+1])
                    while(l<r && nums[l]==nums[l+1])
                        ++l;
                
                if(l<r && nums[r]==nums[r-1])
                    while(l<r && nums[r]==nums[r-1])
                        --r;
            }
        }
        return res;
    }
};