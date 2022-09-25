class MyCircularQueue {
public:
    vector<int> q;
    int size=0;
    int front=0;
    int k=0;
    
    MyCircularQueue(int k) {
        this->k=k;
        q.resize(k);
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        q[(front+size)%k]= value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        front= (front+1)%k;
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return q[(front+size-1)%k];
    }
    
    bool isEmpty() {
        return (size==0)? true: false;
    }
    
    bool isFull() {
        return (size==k)? true: false;
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