class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> res, resIndex;
        vector<int> path(n);
        
        for(int i=0;i<n;i++){
            if(res.empty() || res.back()<nums[i]){
                path[i]=(res.empty())?-1: resIndex[resIndex.size()-1];
                res.push_back(nums[i]);
                resIndex.push_back(i);
            }
            
            else{
                int idx= lower_bound(res.begin(),res.end(), nums[i])-res.begin();
                path[i]=(idx==0)?-1: resIndex[idx-1];
                res[idx]= nums[i];
                resIndex[idx]=i;
            }
        }
        
//         for(int i=0;i<n;i++)
//             cout<<i<<" "<<path[i]<<endl;
        
        vector<int> ans;
        int k= resIndex[resIndex.size()-1];
        while(k!=-1){
            ans.push_back(nums[k]);
            k = path[k];
        }
        return res.size();
    }
};