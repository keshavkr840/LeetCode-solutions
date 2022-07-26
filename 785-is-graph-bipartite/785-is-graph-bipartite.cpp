class Solution {
private:
    bool checkBipartite(vector<vector<int>>& graph, vector<int> &color, int i){
        for(auto &n: graph[i]){
            if(color[n]==-1){
                color[n]= color[i]^1;
                if(!checkBipartite(graph, color,n)) return false;
            }
            else if(color[n]==color[i]) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                if(!checkBipartite(graph,color, i)) return false;
            }
        }
        return true;
    }
};