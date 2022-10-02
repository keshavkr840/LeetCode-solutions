class LUPrefix {
public:
    int v[100001];
    int till=0;
    LUPrefix(int n) {
        memset(v,0, sizeof(v));
    }
    
    void upload(int video) {
        v[video]=1;
        if(till==video-1){
            while(v[1+till])
                till++;
        }
    }
    
    int longest() {
        return till;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */