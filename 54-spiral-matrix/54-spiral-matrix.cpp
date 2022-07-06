class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> ans;
        
        int top=0, bottom= m-1, left=0, right= n-1;
        int dir=1;
        
        while(left<=right && top<=bottom){
            if(dir==1){
                for(int i=left; i<=right;i++) ans.push_back(matrix[top][i]);
                top++;
                dir=2;
            }
            else if(dir==2){
                for(int j=top;j<=bottom;j++) ans.push_back(matrix[j][right]);
                dir=-1;
                right--;
            }
            else if(dir==-1){
                for(int i= right;i>=left;i--) ans.push_back(matrix[bottom][i]);
                bottom--;
                dir=-2;
            }
            else if(dir==-2){
                for(int j=bottom;j>=top;j--) ans.push_back(matrix[j][left]);
                left++;
                dir=1;
            }
        }
        return ans;
    }
};