class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left, right;
        // left[0]=-1;
        // right[n-1]= n;
        
        stack<int> st;
        
        for(int i=0;i<n;i++){
            if(st.empty()) left.push_back(-1);
            
            else if(heights[st.top()] < heights[i])
                left.push_back(st.top());
            else{
                while(!st.empty() && heights[st.top()]>= heights[i])
                    st.pop();
                if(st.empty()) left.push_back(-1);
                else left.push_back(st.top());
            }
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        
        for(int i=n-1;i>=0;i--){
            if(st.empty()) right.push_back(n);
            
            else if( heights[st.top()]< heights[i])
                right.push_back(st.top());
            
            else{
                while(!st.empty() && heights[st.top()]>= heights[i])
                    st.pop();
                
                if(st.empty()) right.push_back(n);
                else right.push_back(st.top());
            }
            st.push(i);
        }
        
        reverse(right.begin(),right.end());
        int mx=0;
        for(int i=0;i<n;i++){
            mx= max(mx, (right[i]-left[i]-1)*heights[i]);
        }
        return mx;
    }
};