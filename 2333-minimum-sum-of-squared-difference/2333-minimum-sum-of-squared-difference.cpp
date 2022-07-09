class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        unordered_map<int, int> map;
        priority_queue<int> pq;
        long long ans=0, sum=0;
        
        int n = nums1.size();
        for(int i=0;i<n;i++){
            int temp= abs(nums1[i]-nums2[i]);
            if (map.find(temp)== map.end())
                pq.push(temp);
            map[temp]++;
            ans+=(long long)temp*temp;
            sum+= temp;
        }
        
        int cnt = k1+k2;
        if(cnt>=sum) return 0;
        
        while(!pq.empty() && cnt>0){
            int temp= pq.top();
            if(temp==0) break;
            pq.pop();
            if(pq.top()!= temp-1) pq.push(temp-1);
            
            int freq= map[temp];
            
            if(freq<=cnt){
                map.erase(temp);
                ans+=(pow(temp-1,2) - pow(temp,2))*freq;
                
                if(temp==1) continue;
                
                if(map.find(temp-1)==map.end())
                    map[temp-1]= freq;
                else map[temp-1]+= freq;
            }
            
            else{
                ans+= cnt*(pow(temp-1,2) - pow(temp,2));
            }
            cnt-= freq;
        }
        return ans;
    }
};