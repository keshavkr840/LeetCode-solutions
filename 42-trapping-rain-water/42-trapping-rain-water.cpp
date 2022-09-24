//https://www.youtube.com/watch?v=m18Hntz4go8&ab_channel=takeUforward
//from 16:20 to 19:20

class Solution {
public:
    int trap(vector<int>& a) {
        int ans=0;
        int mxleft=0, mxright=0;
        int l=0, r= a.size()-1;
        
        while(l<=r){
            //this guarantees that on the other half, there is a building whose min height is that of current element
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
//we know that soln. is min(mxleft, mxright)-height[i]
//so, we compare at each step whether now, the height[l] is less or right is less,
//and we move our pointer from the side which has lesser height
    }
};