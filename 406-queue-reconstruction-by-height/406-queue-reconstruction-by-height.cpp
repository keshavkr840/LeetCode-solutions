class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(),people.end());
        // ,[&](vector<int>&a, vector<int> &b){
        //     if(a[0]==b[0]) return 
        // });
        
        // for(auto v:people)
        //     cout<<v[0]<<" "<<v[1]<<endl;
        
        vector<vector<int>> ans(n, vector<int>(2,-1));
        
        for(int i=0;i<n;i++){
            int second= people[i][1];
            for(int j=0;j<n;j++){
                
                if(ans[j][0]==-1 && second==0){
                    ans[j]= people[i];
                    break;
                }
                else if(ans[j][0]==-1 || ans[j][0]>= people[i][0]) second--;
            }
        }
        return ans;
    }
};