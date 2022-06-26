// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    // code here
	    int mod = 1e9+7;
	    ll one=0, zero=1;
	    ll prev0, prev1;
	    
	    for(int i=1;i<=n;i++){
	        prev0=zero;
	        prev1= one;
	        
	        one= (prev0)%mod;
	        zero= (prev0+ prev1)%mod;
	    }
	    
	    return (one+zero)%mod;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends