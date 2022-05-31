class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> jump(n,INT_MAX);
        jump[0]=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=i+nums[i];j++){
                if(j==n) break;
                jump[j]=min(1+jump[i],jump[j]);
            }
        }
        return jump[n-1];
    }
};