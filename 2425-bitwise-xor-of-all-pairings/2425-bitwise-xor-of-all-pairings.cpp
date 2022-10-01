class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        
        int axor=0;
        for(int i=0;i<m;i++)
            axor^=nums1[i];
        
        int bxor=0;
        for(int i=0;i<n;i++)
            bxor^= nums2[i];
        
        
        return (m%2==0? 0 : bxor)^(n%2==0? 0: axor);
    }
};