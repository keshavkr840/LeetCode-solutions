class Solution {
public:
    bool dfs(vector<int>& edges, vector<bool> &used, vector<int> &temp, unordered_set<int> &map, int i){
        if(used[i]){ 
            if(map.find(i)!= map.end()){
                temp.push_back(i);
                return true;
            }
            else return false;
        }
        
        used[i]= true;
        map.insert(i);
        
        if(edges[i]==-1) return false;
        temp.push_back(i);
        
        if(dfs(edges, used, temp, map, edges[i])) return true;
        
        return false;
    } 
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> used(n,false);
        
        int len=-1;
        
        for(int i=0;i<n;i++){
            
            if(!used[i]){
                
                vector<int> temp;
                unordered_set<int> map;
                if(dfs(edges, used, temp, map, i)){
                    int last = temp.back();
                    temp.pop_back();
                    int templen=1;
                    while(temp.back()!= last){
                        temp.pop_back();
                        templen++;
                    }
                    len = max(len, templen);
                }     
            }
        }
        
        return len;
    }
};