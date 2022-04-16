class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n));
        
        int total = n*n, num=1;
        int x=0, y=-1;
        
        while(num<=total){
            
            for(int i=0;i<n;i++)
                ans[x][++y]= num++;
            
            for(int i=0;i<n-1;i++)
                ans[++x][y]= num++;
            
            for(int i=0;i<n-1;i++)
                ans[x][--y]= num++;
            
            for(int i=0;i<n-2;i++)
                ans[--x][y]=num++;
            
            n-=2;
        }
        return ans;
    }
};
