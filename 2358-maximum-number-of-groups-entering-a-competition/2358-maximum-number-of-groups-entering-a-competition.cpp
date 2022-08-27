class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(), grades.end());
        
        int prevsum=0, prevcnt=0;
        int currsum=0, currcnt=0;
        int cnt=0;
        
        for(auto & grade: grades){
            currsum+= grade;
            currcnt++;
            
            if(currcnt> prevcnt && currsum> prevsum){
                cnt++;
                prevsum= currsum, prevcnt= currcnt;
                currsum= currcnt=0;
            }
        }
        return cnt;
    }
};