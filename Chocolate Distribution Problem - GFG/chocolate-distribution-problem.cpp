// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        if(m==1) return 0;
        sort(a.begin(), a.end());
        if(m==n) return a.back()-a[0];
        
        int minDiff=INT_MAX, diff,l=0;
        for(int i=1;i<n;i++){
            diff= a[i]-a[l];
            if(i+1>=m){
                minDiff= min( minDiff, diff);
                l++;
            }
        }
        return minDiff;
    }   
};

// { Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}  // } Driver Code Ends