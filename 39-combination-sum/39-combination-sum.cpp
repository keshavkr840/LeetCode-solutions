class Solution {
private:
    int req;
    vector<vector<int>> ans;
    void solve(vector<int> &v, int i, vector<int> &temp, int sum){
        if(sum> req) return;
        if(i==v.size()){
            if(sum==req)
                ans.push_back(temp);
            return;
        }
        
        sum+=v[i];
        temp.push_back(v[i]);
        solve(v,i,temp,sum);
        
        temp.pop_back();
        sum-=v[i];
        
        solve(v,i+1,temp,sum);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort(candidates.begin(), candidates.end());
        vector<int> temp;
        req= target;
        solve(candidates,0,temp,0);
        return ans;
    }
};