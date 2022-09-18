class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n = height.size();
        vector<int> left(n,0), right(n,0);
        
        int mx=0;
        for(int i=0;i<n;i++){
            left[i]= mx;
            mx= max(mx, height[i]);
        }
        mx=0;
        for(int i=n-1;i>=0;i--){
            right[i]= mx;
            mx= max(mx, height[i]);
        }
        
        for(int i=0;i<n;i++)
            ans+= max(0,min(left[i], right[i])- height[i]);
        
        return ans;
    }
};