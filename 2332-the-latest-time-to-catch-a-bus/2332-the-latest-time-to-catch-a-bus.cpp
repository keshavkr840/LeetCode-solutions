class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& bus, vector<int>& people, int capacity) {
        sort(bus.begin(), bus.end());
        sort(people.begin(), people.end());
        int totalPeople= people.size();
        
        int prevPerson=-1;
        int currPerson =0;
        
        int icome =1;
        
        for(int i=0;i<bus.size();i++){
            int cap=0;
            int currbus= bus[i];
            
            while(cap<capacity && currPerson< totalPeople && people[currPerson]<= currbus){
                if(people[currPerson]-prevPerson> 1){
                    icome = people[currPerson]-1;
                }
                prevPerson = people[currPerson];
                cap++;
                currPerson++;
            }
            
            if(cap<capacity && prevPerson != currbus){
                icome = currbus;
            }
        }
        return icome;
    }
};