class DSU{
    private:
    vector<int> parent;
    vector<int> rank;
    public:
    void makeSet(int n){
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        rank.resize(n,0);
    }
    int findParent(int u){
        if(u==parent[u])
            return u;
        else 
            return parent[u]= findParent(parent[u]);
    }
    
    void unionn (int u, int v){
        u = findParent(u);
        v = findParent(v);
        
        if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else if(rank[u]>rank[v])
            parent[v]=u;
        
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    int getUnique(int n){
        int unique=0;
        for(int i=0;i<n;i++)
            if(parent[i]==i) unique++;
        return unique;
    }
    
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU * dsu = new DSU();
        
        dsu->makeSet(n);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j] && i!=j){
                    dsu->unionn(i,j);
                }
            }
        }
        
        return dsu->getUnique(n);
    }
};