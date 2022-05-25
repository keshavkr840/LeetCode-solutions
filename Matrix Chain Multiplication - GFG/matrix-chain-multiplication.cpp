// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        int dp[n][n];
        for(int i=1;i<n;i++)dp[i][i]=0;
        
        for(int cl=2;cl<=n;cl++){
            for(int l=1;l<=(n-cl);l++){
                int r= l+cl-1;
                dp[l][r] = INT_MAX;
                
                for(int k=l;k<r;k++){
                    dp[l][r]= min(dp[l][r],
                                    dp[l][k] + dp[k+1][r] + arr[l-1]*arr[k]*arr[r]);
                }
            }
        }
        
        return dp[1][n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends