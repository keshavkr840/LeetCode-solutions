class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        if(n==2) return abs(nums[0]-nums[1]);
        
        int mx= *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        
        if(mx==mn) return 0;
        
        // cout<<mx<<" "<<mn<<endl;
        
        int bucket_size= max(1,(mx-mn)/(n-1));
        
        //adding 1 here otherwise, int idx value for mx will lie out of index, causing Runtime error
        int bucket_num =  1 + (mx-mn)/bucket_size;
        
        vector<int> minValue(bucket_num,INT_MAX), maxValue(bucket_num, INT_MIN);
        
        
        for(auto x: nums){
            // cout<<x<<endl;
            int idx= (x - mn)/bucket_size;
            maxValue[idx]= max(maxValue[idx], x);
            minValue[idx]= min(minValue[idx], x);
        }
        
        int maxGap=INT_MIN;
        int prev= maxValue[0];
        
        for(int i=1;i<bucket_num;i++){
            if(minValue[i]==INT_MAX) continue;
            
            maxGap= max( maxGap, minValue[i]- prev);
            prev= maxValue[i];
        }
        return maxGap;
    }
};