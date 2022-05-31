class Solution {
public:
    int jump(vector<int>& v) {
        int n = v.size()-1;
        if(n==0) return 0;

        int ladder = v[0];
        int stair = v[0];

        int jump =1;

        for(int i=1;i<=n;i++){
            if(i==n) return jump;

            if(i+v[i]> ladder) ladder = i+v[i];

            --stair;
            if(stair==0){
                jump++;
                stair= ladder- i;
            }
        }
        return jump;
    }
};