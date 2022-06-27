class Solution {
private:
    int kadane(vector<int>& n1, vector<int>& n2){
        int n = n1.size();
        int mx = 0,curr=0,sum=0;
        
        for(int i=0;i<n;i++){
            // sum= max(sum+n2[i]-n1[i], n2[i]-n1[i]);
            curr= n2[i]- n1[i];
            if(curr+sum>curr)
                sum+=curr;
            else
                sum= curr;
            
            mx= max(mx,sum); 
        }
        return mx;
    }
public:
    int maximumsSplicedArray(vector<int>& n1, vector<int>& n2) {
        int n = n1.size();
        return max( accumulate(begin(n1), end(n1),0) + kadane(n1,n2), 
                    accumulate(begin(n2), end(n2),0) + kadane(n2,n1));
    }
};
