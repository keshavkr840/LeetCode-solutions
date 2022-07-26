class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);
        
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                queue<int> q;
                q.push(i);
                
                while(!q.empty()){
                    int curr= q.front();
                    q.pop();
                    
                    for(auto &n: graph[curr]){
                        if(color[n]==-1){
                            color[n]= color[curr]^1;
                            q.push(n);
                        }
                        else if(color[n]==color[curr]) return false;
                    }
                }
            }
        }
            
        return true;
    }
};