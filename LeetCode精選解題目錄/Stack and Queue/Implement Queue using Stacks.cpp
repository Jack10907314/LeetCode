class MyQueue {
public:
    stack<int> stack1;
    stack<int> stack2;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        pour_out();
        int a = stack2.top();
        stack2.pop();
        return a;
    }
    
    /** Get the front element. */
    int peek() {
        pour_out();
        return stack2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
    
    void pour_out(){
        if(!stack2.empty())
            return;
        while(!stack1.empty()){
            int a = stack1.top();
            stack2.push(a);
            stack1.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */