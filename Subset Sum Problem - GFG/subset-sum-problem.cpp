// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>A, int B){
        // code here 
        int n = A.size();
    bool dp[n+1][B+1];

    for(int i=0;i<=n;i++)
        dp[i][0]= true;
    
    for(int j=1;j<=B;j++)
        dp[0][j]= false;

    for(int i=1;i<=n;++i){
        for(int j=1;j<=B;j++){
            if(A[i-1]<=j)
                dp[i][j]= dp[i-1][j-A[i-1]] || dp[i-1][j];
            
            else 
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][B];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends