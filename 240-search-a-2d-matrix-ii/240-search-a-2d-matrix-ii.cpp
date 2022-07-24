class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        for(int i=0;i<matrix.size();i++){
            auto it = lower_bound(matrix[i].begin(), matrix[i].end(), target)- matrix[i].begin();
            if(it< matrix[0].size() && matrix[i][it]== target) return true;
        }
        return false;
    }
};