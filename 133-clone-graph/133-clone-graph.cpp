/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*, Node*> map;
        Node* first= new Node(node->val, {});
        
        map[node]= first;
        
        queue<Node*> q;
        q.push(node);
        
        
        while(!q.empty()){
            auto curr= q.front();
            q.pop();
            
            for(auto &adj: curr->neighbors){
                if(map.find(adj)==map.end()){
                    map[adj]= new Node(adj->val, {});
                    q.push(adj);
                }
                
                map[curr]->neighbors.push_back(map[adj]);
            }
        }
        return map[node];
    }
};