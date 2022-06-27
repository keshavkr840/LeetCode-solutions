class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> map;
        for(auto n:tasks) map[n]++;
        
        int ans=0;
        for(auto it= map.begin();it!= map.end();it++){
            if (it->second==1) return -1;
            else ans+= it->second/3 + ((it->second%3==0)?0:1);
            
            // cout<<it->first<<" : "<<it->second<<endl;
        }
        return ans;
    }
};