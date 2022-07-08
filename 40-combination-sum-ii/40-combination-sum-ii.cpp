class Solution {
private:
    vector<vector<int>> ans;
    void solve(vector<int> &v, vector<int> &temp, int req, int i){
        if(req==0) {
            ans.push_back(temp);
            return;
        }
        if(i==v.size()) return;
        if(v[i]<=req)
        {
            req-=v[i]; temp.push_back(v[i]);
            solve(v, temp,req, i+1);
            req+=v[i]; temp.pop_back();
        }
        
        while(i+1<v.size() && v[i+1]==v[i]) i++;
        
        solve(v,temp,req,i+1);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(candidates, temp, target, 0);
        return ans;
    }
};