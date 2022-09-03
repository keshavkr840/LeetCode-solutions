class Solution {
public:
    int mx=0;
    void recurse(vector<vector<int>>& mat, vector<int> &check, unordered_set<int> &map, int cols, int idx){
        if(idx==mat[0].size() && cols==0){
            int temp=0;
            for( auto & row: check){
            int sum=0;
                for(int i=0;i<mat[0].size();i++){
                    if(map.find(i)== map.end() && mat[row][i])
                        sum++;
                }
                if(sum==0)temp++;
            }
            mx = max(mx, temp);
        }
        
        for(int i=idx;i<mat[0].size();i++){
            if(cols> mat[0].size()- i) break;
            bool flag = false;
            if(cols>0){
                map.insert(i);
                cols--;
                flag = true;
            } 
            recurse(mat, check, map, cols, i+1);
            if(flag){
                map.erase(i);
                cols++;
            }
        }
    }
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m = mat.size(), n = mat[0].size();
        vector<int> check;
        int ans=0;
        
        for(int i=0;i<m;i++){
            int sum= accumulate(mat[i].begin(), mat[i].end(),0);
            if(sum==0) ans++;
            else check.push_back(i);
        }
        
        unordered_set<int> map;
        recurse(mat, check, map, cols, 0);
        
        
        return ans+mx; 
    }
};