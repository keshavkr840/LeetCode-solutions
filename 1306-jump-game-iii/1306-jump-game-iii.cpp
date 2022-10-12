class Solution {
private:
    bool solve(vector<int>& arr, vector<bool> &vis, int &n, int i){
        if(vis[i])
            return false;
        
        if(arr[i]==0) return true;
        
        vis[i]= true;
        bool zero= false;
        
        if(arr[i]+i<n)
            zero= solve(arr, vis, n, i+arr[i]);
        
        if(zero)return true;
        
        if(i>=arr[i])
            zero= solve(arr, vis, n, i-arr[i]);
        
        
        return zero;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n =arr.size();
        vector<bool> vis(n,false);
        return solve(arr, vis, n, start);
    }
};