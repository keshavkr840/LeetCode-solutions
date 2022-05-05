class Solution {
public:
    int totalGroups(int mid, vector<int>& piles){
        int ans=0;
        int rem;
        for(auto &n:piles){
            rem=n%mid;
            if(rem >0) ans+= (n/mid) +1;
            else ans+= (n/mid);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, hi=INT_MAX;
        
        while(l<hi){
            int mid =l+(hi-l)/2;
            if(totalGroups(mid,piles)>h) l=mid+1;
            else hi= mid;
        }
        return l;
    }
};