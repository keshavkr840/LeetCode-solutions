class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> small, large;
        vector<double> ans;
        int n = nums.size();
        double temp;
        
        for(int i=0;i<n;i++){
            if(large.empty() || nums[i]>= *large.begin())
                large.insert(nums[i]);
            else 
                small.insert(nums[i]);
            
            if(i>=k){
                if(nums[i-k]>= *large.begin())
                    large.erase(large.find(nums[i-k]));
                else
                    small.erase(small.find(nums[i-k]));
            }
            
            while(small.size() > large.size()){
                large.insert(*small.rbegin());
                small.erase(--small.end());
            }
            while(small.size()+ 1<large.size()){
                small.insert(*large.begin());
                large.erase(large.begin());
            }
            
            if(i+1>=k){
                
                if(k & 1) temp= *large.begin();
                else temp= ((double)*large.begin()+ *small.rbegin())/2.0;
                
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
