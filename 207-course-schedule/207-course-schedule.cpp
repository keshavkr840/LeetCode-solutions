class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        
        for(auto &v: prereq){
            indegree[v[0]]++;
            adj[v[1]].push_back(v[0]);
        }
        
        queue<int> q;
        for(int i=0;i<n;i++)
            if(indegree[i]==0) q.push(i);
        
        while(!q.empty()){
            auto curr= q.front();
            q.pop();
            
            for(auto &e: adj[curr]){
                indegree[e]--;
                if(indegree[e]==0) q.push(e);
            }
        }
        
        for(auto &e : indegree)
            if(e!=0) return false;
        return true;
    }
};