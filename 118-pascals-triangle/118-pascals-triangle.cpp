class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        ans.push_back({1});
        
        // for(int i=0;i<n;i++){
        //     dp[i][0]= dp[i][i]=1;
        // }

        for(int i=1; i<n; i++){
            vector<int> temp;
            temp.push_back(1);
            
            for(int j=1;j<i;j++){
                temp.push_back(ans.back()[j-1] + ans.back()[j]);
            }
            temp.push_back(1);
            ans.push_back(temp);
            // k++;
        }
        
        // vector<vector<int>> ans;
        return ans;
    }
};