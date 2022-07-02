class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int m = nums1.size();
        int n = nums2.size();
        
        int total= (m+n+1)/2;
        
        int start=0, end=m;
        
        while(start<=end){
            int partX= (start+end)/2;
            int partY= total- partX;
            
            int lastmX= (partX==0)?INT_MIN: nums1[partX-1];
            int firstmX= (partX==m)?INT_MAX: nums1[partX];
            
            int lastnY= (partY==0)? INT_MIN: nums2[partY-1];
            int firstnY= (partY==n)? INT_MAX: nums2[partY];
            
            if(lastmX<=firstnY && lastnY<= firstmX){
                return ((m+n)%2==0)? (max(lastmX, lastnY)+ min(firstmX, firstnY))/2.0 : max(lastmX, lastnY);
            }
            
            else{
                if(lastmX>firstnY) end= partX-1;
                else start= partX+1;
            }
        }
        return INT_MIN;
    }
};