class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int row_i= m-1, col_i = 0;
        
        while(row_i>=0 && col_i<n){
            int curr= matrix[row_i][col_i];
            
            if(curr== target) return true;
            
            if(curr> target)
                row_i--;
            else 
                col_i++;
        }
        return false;
    }
};