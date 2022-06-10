class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        if(m==0){
            nums1= nums2;
            return;
        }
        int size = nums1.size();
        int l= m-1, r=size-1, k=n-1;
        
        while(l>=0 && k>=0){
            if(nums1[l]>nums2[k]) nums1[r--]= nums1[l--];
            else nums1[r--]= nums2[k--];
            
            // for(auto em: nums1) cout<<em<<",";
            // cout<<endl;
        }
        while(k>=0){
            nums1[r--]=nums2[k--];
        }
    }
};