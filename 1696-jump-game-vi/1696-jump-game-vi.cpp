class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return nums[0];
        
        priority_queue<pair<int, int>> pq;
        // vector<int> ans(n,INT_MIN);
        int curr=0;
        pq.push({nums[0],0});
        
        
        for(int i=1;i<n;i++){
            while(!pq.empty() && pq.top().second<i-k)
                pq.pop();
            curr= nums[i]+ pq.top().first;
            pq.push({curr,i});
        }
        
        // for(auto &n: ans) cout<<n<<" ";
        return curr;
    }
};