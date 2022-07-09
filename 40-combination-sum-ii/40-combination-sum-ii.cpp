class Solution {
private:
    vector<vector<int>> ans;
    void solve(vector<int> &v, vector<int> &temp, int req, int idx){
        if(req==0) {
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<v.size();i++){
            if(i> idx && v[i]==v[i-1]) continue;
            if(v[i]> req) break;
            
            temp.push_back(v[i]);
            
            // for(auto &n : temp) cout<<n<<" ";
            // cout<<endl;
            // silly mistake, i passed idx+1, instead of i+1
            solve(v, temp, req-v[i], i+1);
            temp.pop_back();
        }
    }
  //   void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
  // if (target == 0) {
  //   ans.push_back(ds);
  //   return;
  // }
  // for (int i = ind; i < arr.size(); i++) {
  //   if (i > ind && arr[i] == arr[i - 1]) continue;
  //   if (arr[i] > target) break;
  //   ds.push_back(arr[i]);
  //   findCombination(i + 1, target - arr[i], arr, ans, ds);
  //   ds.pop_back();
  // }
// }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(candidates, temp, target, 0);
        return ans;
    }
    // vector < vector < int >> combinationSum2(vector < int > & candidates, int target) {
    //       sort(candidates.begin(), candidates.end());
    //       vector < vector < int >> ans;
    //       vector < int > ds;
    //       findCombination(0, target, candidates, ans, ds);
    //       return ans;
    // }
};

