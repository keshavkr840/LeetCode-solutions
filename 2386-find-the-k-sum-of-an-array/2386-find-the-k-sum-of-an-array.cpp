class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        int sz= nums.size();
        long long mx=0;
        for(auto &n : nums){
            if(n>=0) mx+=n;
            else n=-n;
        }
        if(k==1) return mx;
        
        sort(nums.begin(), nums.end());
        
        using ip = std::pair<long long, int>;
        priority_queue<ip, vector<ip>, greater<ip>>pq;
        pq.push({nums[0],0});
        vector<long long > subt;
        
        while(!pq.empty() && subt.size()<k-1){
            auto [el,idx]= pq.top();
            pq.pop();
            
            subt.push_back(el);
            
            if(idx<sz-1){
                pq.push({nums[idx+1]+ el, idx+1});
                pq.push({nums[idx+1]+ el- nums[idx], idx+1});
            }
        }
        // for(auto &n: subt)
        //     cout<<n<<" ";
        // cout<<endl;
        return mx- subt[k-2];
        
    }
};