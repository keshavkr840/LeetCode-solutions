class Solution {
private:
    int m,n,bc;
    void func(vector<vector<int>>& image,int sr, int sc,int &color){
        if(sr<0 || sc<0 || sr==m || sc==n) return;
        if(image[sr][sc]==bc){
            image[sr][sc]= color;
            func(image, sr, sc-1, color);
            func(image, sr, sc+1, color);
            func(image, sr-1, sc, color);
            func(image, sr+1, sc, color);
        }
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        this->m = image.size();
        this->n = image[0].size();
        this->bc = image[sr][sc];
        
        if(bc!=color)
            func(image, sr, sc, color);
        return image;
    }
};