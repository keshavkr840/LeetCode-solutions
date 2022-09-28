class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        
        set<pair<int,int>> s;
        
        // sort(circles.rbegin(),circle.rend());
        int x, y, r;
        
        for(auto &circle: circles){
            x= circle[0], y= circle[1], r= circle[2];
        
            for(int i= x-r;i<= x+r; i++){
                for(int j = y-r;j<= y+r; j++){
                    if(s.find(make_pair(i,j))==s.end())
                        if(pow((i-x),2)+ pow((j-y),2)<= r*r)
                            s.insert({i,j});
                }
            }
        }
        
        return s.size();
    }
};