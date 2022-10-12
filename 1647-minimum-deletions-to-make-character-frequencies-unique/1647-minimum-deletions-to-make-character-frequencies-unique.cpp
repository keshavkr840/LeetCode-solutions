class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(auto &c:s)
            freq[c-'a']++;
        
        // for(auto&n: freq)
        //     cout<<n<<" ";
        // cout<<endl;
        
        sort(freq.begin(), freq.end());
        int begin = upper_bound(freq.begin(), freq.end(), 0)- freq.begin();
        
        // for(auto&n: freq)
        //     cout<<n<<" ";
        // cout<<endl;
        int ans=0, mx=INT_MAX,del=0;
        
        for(int i=25;i>=begin;i--){
            if(mx==0){
                for(;i>=begin; i--)
                    ans+=freq[i];
                break;
            }
            else if(freq[i]<=mx)
                mx= freq[i]-1;
            else{
                del = freq[i]-mx;
                mx= freq[i]-del-1;
                ans+=del;
            }
        }
        return ans;
        
    }
};