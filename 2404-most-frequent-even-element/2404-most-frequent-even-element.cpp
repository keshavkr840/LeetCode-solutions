class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> map;
        int freq=0, num=INT_MAX;
        
        for(auto &n: nums){
            if(n%2==0){
                map[n]++;
                
                if(map[n]> freq || map[n]==freq && n<num){
                    freq= map[n];
                    num= n;
                }
            }
        }
        
        
        return (num==INT_MAX)?-1: num;
    }
};