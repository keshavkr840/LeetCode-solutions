// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501][501];
    bool isPalindrome(string & str, int i, int j){
        while(i<j){
            if(str[i]!=str[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
    int solve(string & str, int i, int j){
        if(i>=j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if (isPalindrome(str, i,j)) return dp[i][j]=0;
        
        int mn = INT_MAX;
        for(int k =i;k<j;k++){
            int temp = solve(str,i,k) +1 + solve(str,k+1,j);
            
            mn = min(temp,mn);
        }
        return dp[i][j]= mn;
    }
    int palindromicPartition(string str)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(str,0,str.size()-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends