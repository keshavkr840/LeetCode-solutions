class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> map;
        
        for(auto &n: tasks)
            map[n]++;
        
        int ans=0;
        for(auto it: map){
            if((it.second)==1) return -1;
            else{
                ans+=it.second/3;
                ans+=(it.second%3==0)?0:1;
            }
                // ans+= (it.second%3==2)?1:0 + it.second/3;
        }
        return ans;
    }
};