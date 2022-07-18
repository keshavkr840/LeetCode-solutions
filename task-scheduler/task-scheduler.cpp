class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) return tasks.size();
        int ans=0;
        
        vector<int> hash(26,0);
        for(auto &c: tasks)
            hash[c-'A']++;
        
        priority_queue<int> pq;
        for(auto &num: hash){
            if(num!=0) pq.push(num);
        }
        
        int extraSpace=0;
        while(!pq.empty()){
            vector<int> store(n+1);
            int i=0;
            for(i;i<=n;i++){
                if(pq.empty()) break;
                ++ans;
                store[i]= pq.top()-1;
                pq.pop();
            }
            if(i!=n+1){
                extraSpace=(n-i+1);
                ans+=extraSpace;
            } 
            
            for(i=0;i<=n;i++){
                if(store[i]!=0) pq.push(store[i]);
                else break;
            }
        }
        return ans-extraSpace;   
    }
};