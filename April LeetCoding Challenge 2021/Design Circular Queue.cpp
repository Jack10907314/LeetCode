class MyCircularQueue {
public:
    bool full = false;
    int l = 0;
    int r = 0;
    int k = 0;
    vector<int> queue;
    MyCircularQueue(int k) {
        queue = vector<int>(k,0);
        this->k = k;
    }
    
    bool enQueue(int value) {
        if(!isFull()){
            queue[r] = value;
            r++;
            if(r == k) r = 0;
            if(r == l) full = true;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(!isEmpty()){
            l++;
            if(l == k) l = 0;
            full = false;
            return true;
        }
        return false;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return queue[l];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        if(r-1 == -1)
            return queue[k-1];
        return queue[r-1];
    }
    
    bool isEmpty() {
        if(!full && r == l)
            return true;
        return false;
    }
    
    bool isFull() {
        if(full)
            return true;
        return false;
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