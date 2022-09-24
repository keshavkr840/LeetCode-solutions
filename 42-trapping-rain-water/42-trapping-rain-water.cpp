class Solution {
public:
    int trap(vector<int>& a) {
        int ans=0;
        int mxleft=0, mxright=0;
        int l=0, r= a.size()-1;
        
        while(l<=r){
            if(a[l]<=a[r]){
                if(a[l]>= mxleft)
                    mxleft= a[l++];
                else
                    ans+=mxleft-a[l++];
            }
            
            else{
                if(a[r]>=mxright)
                    mxright= a[r--];
                else
                    ans+= mxright-a[r--];
            }
        }
        
        return ans;
        
    }
};