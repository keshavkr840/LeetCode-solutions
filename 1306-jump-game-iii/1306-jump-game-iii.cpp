class Solution {
private:
    bool solve(vector<int>& arr, int &n, int i){
        if(i>=0 && i<n  && arr[i]!=-1){
            if(arr[i]==0) return true;
            int curr= arr[i];
            arr[i]=-1;
            
            return (solve(arr, n, i+curr) || solve(arr, n, i-curr));
                
        }
        return false;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n =arr.size();
        return solve(arr, n, start);
    }
};