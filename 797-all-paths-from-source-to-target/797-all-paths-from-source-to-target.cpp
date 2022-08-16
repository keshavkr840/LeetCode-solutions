class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<vector<int>> &ans, vector<int> &path, int src, int &dest){
        path.push_back(src);
        if(src==dest)
            ans.push_back(path);
        
        for(auto &it: graph[src]){
            dfs(graph, ans, path, it, dest);
        }
        
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        int dest = graph.size()-1;
        dfs(graph, ans, path, 0, dest);
        return ans;
    }
};