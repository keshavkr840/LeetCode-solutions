class Solution {
private:
    vector<bool> map;
    bool solve(vector<int> &match, long long &target, int parts, int idx, int sum){
        if(parts==1) return true;
        
        if(sum==target) return solve(match, target, parts-1, 0, 0);
        
        for(int i= idx;i<match.size();i++){
            if(map[i] ) continue;
            if(sum+ match[i] > target) break;
            
            map[i]= true;
            if(solve(match, target, parts,i+1, sum+match[i]) ) return true;
            
            map[i]= false;
        }
        return false;
    }

public:
    bool makesquare(vector<int>& match) {
        sort(match.begin(), match.end());
        long long sum= accumulate(match.begin(), match.end(),0);
        int mx = *max_element(match.begin(), match.end());
        
        if(sum%4!=0 || mx> (sum/4)) return false;
        map.resize(match.size(), false);
        sum/=4;
        return solve(match, sum,4, 0,0);
    }
};