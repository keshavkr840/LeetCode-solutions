class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return nums[0];
        
        priority_queue<pair<int, int>> pq;
        vector<int> ans(n,INT_MIN);
        ans[0]= nums[0];
        pq.push({ans[0],0});
        
        
        for(int i=1;i<n;i++){
            while(!pq.empty() && pq.top().second<i-k)
                pq.pop();
            ans[i]= nums[i]+ pq.top().first;
            pq.push({ans[i],i});
        }
        
        // for(auto &n: ans) cout<<n<<" ";
        return ans[n-1];
    }
};