class MyCalendar {
public:
    set<pair<int, int>> set;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(set.empty()){
            set.insert({start,end});
            return true;
        }
        else{
            auto it = set.upper_bound({start,end});
            if(it==set.end()){
                
                it--;
                pair<int,int> p= *it;
                if(p.second <= start){
                    set.insert({start,end});
                    return true;
                }
                return false;
            }
            
            else if(it== set.begin()){
                // it++;
                pair<int,int> p= *it;
                if(end<= p.first){
                    set.insert({start,end});
                    return true;
                }
                return false;
            }
            else{
                pair<int,int> p= *it;
                it--;
                pair<int,int> q= *it;
                
                if(q.second <= start && end<= p.first){
                    set.insert({start,end});
                    return true;
                }
                else return false;
            }
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */