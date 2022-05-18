// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}// } Driver Code Ends

#include<bits/stdc++.h>
int minDeletions(string a, int n) { 
    //complete the function here 
    //string b= reverse(a.begin(), a.end());
    string b=a;
    reverse(b.begin(), b.end()); 
    
    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1])
                dp[i][j]= dp[i-1][j-1]+1;
                
            else
                dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    return n-dp[n][n];
} 