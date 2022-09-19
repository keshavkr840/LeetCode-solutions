class Solution {
private:
    unordered_map<int, int> map;
    int day(string &s){
        int month = stoi(s.substr(0,2));
        int day = stoi(s.substr(3,2));
        
        int days= 0;
        for(int i=0;i<month;i++)
            days+=map[i];
        
        return days+day;
    }
    void init_map(){
        map[1]=31;
        map[2]=28;
        map[3]=31;
        map[4]=30;
        map[5]=31;
        map[6]=30;
        map[7]=31;
        map[8]=31;
        map[9]=30;
        map[10]=31;
        map[11]=30;
        map[12]=31;
        
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        if(arriveAlice > arriveBob)
            return countDaysTogether(arriveBob, leaveBob, arriveAlice, leaveAlice);
        
        init_map();
        
        int dayaA= day(arriveAlice);
        int daydA= day(leaveAlice);
        int dayaB= day(arriveBob);
        int daydB= day(leaveBob);
        
        if(daydA<= dayaB)
            return daydA==dayaB;
        
        int end= min(daydA, daydB);
        
        return end-dayaB+1;
    }
};