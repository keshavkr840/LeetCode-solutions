class Solution {
private:
    bool vis[6][6];
    bool solve(vector<vector<char>>& board, string &word,int &m , int &n, int row, int col, int idx){
        if(idx==word.size()) return true;
        if(row<0 || row==m|| col<0 || col==n) return false;
        
        if(word[idx]==board[row][col]){
            char c= board[row][col];
            board[row][col]='0';
            
            if(solve(board, word, m, n, row, col-1, idx+1)) return true;
            if(solve(board, word, m, n, row, col+1, idx+1)) return true;
            if(solve(board, word, m, n, row-1, col, idx+1)) return true;
            if(solve(board, word, m, n, row+1, col, idx+1)) return true;
            
            board[row][col] = c;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        memset(vis, false, sizeof(false));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(solve(board,word,m, n,i, j, 0))
                    return true;
            }
        }
        return false;
    }
};