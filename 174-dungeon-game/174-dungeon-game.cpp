class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        if(mat[m-1][n-1]>0)
            mat[m-1][n-1]=0;
        for(int j= n-2;j>=0;j--){ 
            mat[m-1][j] += mat[m-1][j+1];
            mat[m-1][j]= (mat[m-1][j]>0)?0: mat[m-1][j];
        }
        
        for(int i= m-2;i>=0;i--){
            mat[i][n-1] += mat[i+1][n-1];
            mat[i][n-1] = (mat[i][n-1]>0)?0: mat[i][n-1];
        }
        
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                mat[i][j]+= max(mat[i+1][j], mat[i][j+1]);
                if(mat[i][j]>0)
                    mat[i][j]=0;
            }
        }
        return (mat[0][0]>0)?1: 1+ abs(mat[0][0]);
    }
};