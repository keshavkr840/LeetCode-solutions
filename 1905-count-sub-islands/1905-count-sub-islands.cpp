class Solution {
private:
    bool isSub(vector<vector<int>>& A, vector<vector<int>>& B, int i, int j){
        if(i<0 || j<0 || i>= A.size() || j>= A[0].size() || B[i][j]==0)
            return true;
        
        B[i][j]=0;
        
        
        bool a= isSub(A, B, i, j-1);
        bool b= isSub(A, B, i, j+1);
        bool c= isSub(A, B, i-1, j);
        bool d= isSub(A, B, i+1, j);
        
        if(A[i][j]==0) return false;
        
        return a&b&c&d;
    }
public:
    int countSubIslands(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size();
        int n = A[0].size();
        
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(B[i][j]==1)
                    if(isSub(A,B, i, j))
                        ans++;
            }
        }
        return ans;
    }
};