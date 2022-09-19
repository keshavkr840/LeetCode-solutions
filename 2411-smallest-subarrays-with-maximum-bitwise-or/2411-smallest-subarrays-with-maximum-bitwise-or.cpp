class Solution {
private:
    int bits(int num){
        int cnt =0;
        while(num>0){
            ++cnt;
            num/=2;
        }
        return cnt;
    }
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size();
        int mx= *max_element(nums.begin(), nums.end());
        int bit= bits(mx);
        
        vector<int> ans(n,0);
        
        for(int i=n-1;i>=0;i--){
            int temp, cnt=1;
            for(int b= 0; b<= bit; b++){
                temp = nums[i] &(1<<b);
                
                if(!temp){
                    if(map.find(b)!=map.end())
                        cnt= max(map[b]-i+1, cnt);
                }
                else
                    map[b]= i;
                
            }
            ans[i]=cnt;
        }
        return ans;
    }
};