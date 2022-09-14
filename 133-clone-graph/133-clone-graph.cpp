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
        if(!node) return NULL;
        unordered_map<Node*, Node*> map;
        Node* temp= new Node(node->val);
        map[node]= temp;
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()){
            auto curr= q.front();
            q.pop();
            
            for(auto &n : curr->neighbors){
                if(map.find(n)==map.end()){
                    map[n]= new Node(n->val);
                    q.push(n);
                }
                    
                map[curr]->neighbors.push_back(map[n]);
                
            }
        }
        
        return temp;
    }
};