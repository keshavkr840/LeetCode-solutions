class MedianFinder {
private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if(small.empty() || small.top()> num) 
            small.push(num);
        else
            large.push(num);
        
        int a= small.size();
        int b= large.size();
        
        if(a> b+1){
            large.push(small.top());
            small.pop();
        }
        if(b> a+1){
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        int a= small.size();
        int b= large.size();
        if(a==b) return (small.top()+ large.top())/2.0;
        else return (a>b)? small.top(): large.top(); 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */