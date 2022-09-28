class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int,int> map;
        for(auto &flower: flowers){
            ++map[flower[0]];
            --map[flower[1]+1];
        }
        vector<int> num, val;
        
        int curr=0;
        for(auto &it: map){
            curr+= it.second;
            num.push_back(it.first);
            val.push_back(curr);
        }
        
//         for(auto &n: num)
//             cout<<n<<", ";
//         cout<<endl;
        
//         for(auto &n: val)
//             cout<<n<<", ";
//         cout<<endl;
        
        vector<int> ans;
        for(auto &person: persons){
            if(person< num[0] || person> num.back())
                ans.push_back(0);
            else{
                auto it= upper_bound(num.begin(), num.end(), person)- num.begin();
                it--;
                // cout<<it<<endl;
                ans.push_back(val[it]);
            }
        }
        
        return ans;
        
    }
};