class MyCircularQueue {
public:
    vector<int> q;
    int front=0, rear=-1;
    bool empty= true;
    int k =0;
    
    MyCircularQueue(int k) {
        this->k = k;
        q.resize(k,-1);
    }
    
    bool enQueue(int value) {
        if(empty){
            rear= (rear+1)%k;
            q[rear]= value;
            empty = false;
            
            return true;
        }
        else{
            if((rear+1)%k ==front)
                return false;
            else{
                rear= (rear+1)%k;
                q[rear]= value;
                
                return true;                
            }
        }
    }
    
    bool deQueue() {
        if(empty) return false;
        if(rear==front)
            empty = true;
        q[front]= -1;
        front= (front+1)%k;
        return true;
    }
    
    int Front() {
        if(empty) return -1;
        else
            return q[front];
    }
    
    int Rear() {
        if(empty) return -1;
        else
            return q[rear];
    }
    
    bool isEmpty() {
        if(empty) return true;
        return false;
    }
    
    bool isFull() {
        if(empty)
            return false;
        else{
            if((1+ rear)%k== front)
                return true;
            return false;
        }
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */