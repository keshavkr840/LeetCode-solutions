class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> baseMap(26,0);
        for(auto &word : B){
            vector<int> currCount(26,0);
            for(auto &c : word)
                currCount[c-'a']++;
            
            for(int i=0;i<26;i++)
                baseMap[i]= max(baseMap[i], currCount[i]);
        }
        
        vector<string> ans;
        for(auto & word: A){
            bool flag = true;
            
            vector<int> currMap(26,0);
            for(auto &c: word)
                currMap[c-'a']++;
            
            for(int i=0;i<26;i++){
                if(currMap[i]<baseMap[i]){
                    flag = false;
                    break;
                }
            }
            
            if(flag) ans.push_back(word);
        }
        return ans;
    }
};