class Solution {
public:
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
        int mod = 1e9+7;
        sort(hCuts.begin(), hCuts.end());
        sort(vCuts.begin(),vCuts.end());
        
        int m = hCuts.size(), n = vCuts.size();
        
        int max_h= max(hCuts[0],h- hCuts.back());
        int max_w= max(vCuts[0],w- vCuts.back());
        
        for(int i=1;i<m;i++)
            max_h= max(max_h, hCuts[i]-hCuts[i-1]);
        
        for(int i=1;i<n;i++)
            max_w= max(max_w, vCuts[i]-vCuts[i-1]);
        
        // int hPrev=0;
        // for(int i=0;i<m;i++){
        //     int vPrev=0;
        //     for(int j=0;j<n;j++){
        //         tempans= ((long long int)((vCuts[j]-vPrev)%mod) * ((long long int)hCuts[i]-hPrev))%mod;
        //         ans= max(ans,tempans);
        //         vPrev=vCuts[j];
        //         cout<<tempans<<" ";
        //     }
        //     cout<<endl;
        //     hPrev= hCuts[i];
        // }
        
        // return ans%mod;
        
        return ((long)max_h* max_w)%mod;
    }
};