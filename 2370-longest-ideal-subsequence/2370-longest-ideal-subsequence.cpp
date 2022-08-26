class Solution {
public:
    int longestIdealString(string s, int k) {
        unordered_map<char, int> map;
        int n = s.size();
        vector<int> v(n,0);
        
        int mx;
        for(int i=0;i<n;i++){
            mx=0;
            for(int j=0;j<=k;j++){
                if(((s[i]+j)<= 'z') && map.find(s[i]+j)!= map.end() )
                    mx= max(mx, map[s[i]+j]);
                if(((s[i]-j)>= 'a') && map.find(s[i]-j)!= map.end() )
                    mx= max(mx, map[s[i]-j]);
            }
            // cout<<mx<<endl;
            v[i]=1+mx;
            map[s[i]]= 1+mx;
        }
        return *max_element(v.begin(), v.end());
    }
};