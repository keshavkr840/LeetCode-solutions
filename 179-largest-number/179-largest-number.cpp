class Solution {
public:
    static bool comp(int & a, int &b){
        string num1 = to_string(a);
        string num2 = to_string(b);
        
        return num1+ num2> num2+ num1;
//         int i=0, k = min(num1.size(), num2.size());
        
//         int flag =0;
//         while(i<k){
//             if(num1[i]==num2[i]){
//                 i++;
//                 continue;
//             }
//             else{
//                 if(num1[i]<num2[i]) flag = 1;
//                 break;
//             }
//         }
//         if(flag==0) return true;
//         else return false;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        string ans="";
        
        if(nums[0]==0) return "0";
        
        for(auto &n:nums){
            ans+=to_string(n);
        }
        return ans;
    }
};