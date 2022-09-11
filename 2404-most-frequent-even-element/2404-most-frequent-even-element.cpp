class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> map;
        
        for(auto &n: nums){
            if(n%2==0){
                map[n]++;
            }
        }
        int freq=0, num=INT_MAX;
        
        for(auto & it: map){
            if(it.second== freq){
                num= min(it.first, num);
            }
            else if(it.second> freq){
                num= it.first;
                freq= it.second;
            }
        }
        
        return (num==INT_MAX)?-1: num;
    }
};