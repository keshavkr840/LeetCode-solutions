class NumMatrix {
public:
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix) {
        for(auto v :matrix){
            vector<int> vec;
            vec.push_back(v.front());
            int size=v.size();
            
            for(int i=1;i<size;i++){
                vec.push_back(v[i]+vec.back());
            }
            mat.push_back(vec);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        for(int i=row1;i<=row2;i++){
            ans+=mat[i][col2];
        }
        
        if(col1>0){
            for(int i=row1;i<=row2;i++){
                ans-=mat[i][col1-1];
            }
        }
            
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */