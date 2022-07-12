class Solution {
private:
    vector<vector<string>> ans;
    bool fill(vector<string> &temp, int &i, int &j, int &n){
        int x= i-1, y=j-1;
        while(x>=0 && y>=0){
            if(temp[x--][y--]=='Q') return false;
        }
        
        x= i-1, y=j;
        while(x>=0){
            if(temp[x--][y]=='Q') return false;
        }
        
        x=i-1, y=j+1;
        while(x>=0 && y<n){
            if(temp[x--][y++]=='Q') return false;
        }
        return true;
    }
    
    void solve(vector<string> &temp, int &n, int row){
        if(row==n)
            ans.push_back(temp);
        
        for(int i=0;i<n;i++){
            if(fill(temp, row, i, n)){
                temp[row][i]='Q';
                solve(temp, n, row+1);
                temp[row][i]='.';
            }
        }
        
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        string str="";
        for(int i=0;i<n;i++) str+=".";
        vector<string> temp (n,str );
        solve(temp, n, 0);
        return ans;
    }
};