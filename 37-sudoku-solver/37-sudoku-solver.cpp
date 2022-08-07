class Solution {
private:
    bool canPlace(vector<vector<char>>& board, int row, int col, char ch){
        for(int i=0;i<9;i++){
            if(board[row][i]==ch || board[i][col]==ch) return false;
        }
        
        int x= row-row%3, y = col- col%3;
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[x+i][y+j]==ch) return false;
        
        return true;
    }
    
    bool solve(vector<vector<char>>& board, int row, int col){
        if(row==9) return true;
        if(col==9) return solve(board, row+1,0);
        
        if(board[row][col]!='.') 
            return solve(board, row, col+1);
        
        else{
            for(char ch ='1'; ch<='9'; ch++){
                if(canPlace(board, row, col, ch)){
                    board[row][col]=ch;
                    if(solve(board, row, col+1)) return true;
                    board[row][col]='.';
                }
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};