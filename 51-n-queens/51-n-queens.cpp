class Solution {
private:
    bool canPlace(vector<vector<string>> &ans, vector<string> &temp, vector<bool> &top, vector<bool> & leftDiagonal, vector<bool> & rightDiagonal, int &n, int row, int col){
        
        if(!top[col] && !leftDiagonal[n-1+(col-row)] && !rightDiagonal[row+col]) return true;
        else return false;
        
    }
    
    
    void solve(vector<vector<string>> &ans, vector<string> &temp, vector<bool> &top, vector<bool> & leftDiagonal, vector<bool> & rightDiagonal, int &n, int row){
        if(row==n){
            ans.push_back(temp);
            return;
        }
        
        for(int col=0;col<n;col++){
            if(canPlace(ans, temp, top, leftDiagonal, rightDiagonal, n, row, col)){
                top[col]= true;
                leftDiagonal[n-1+ (col-row)]=true;
                rightDiagonal[row+col]=true;
                temp[row][col]= 'Q';
                
                solve(ans, temp, top, leftDiagonal, rightDiagonal, n, row+1);
                
                temp[row][col]='.';
                top[col]= false;
                leftDiagonal[n-1+ (col-row)]= false;
                rightDiagonal[row+col]=false;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string str(n, '.');
        vector<bool> top(n,false), leftDiagonal(2*n-1,false), rightDiagonal(2*n-1,false);
        vector<string> temp(n,str);
        
        solve(ans, temp, top, leftDiagonal, rightDiagonal,n, 0);
        return ans;
    }
};