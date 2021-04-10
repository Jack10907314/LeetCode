class FreqStack {
public:
    unordered_map<int,int> myqueue;
    deque<int> mystack;
    FreqStack() {
        
    }
    
    void push(int x) {
        
        ++myqueue[x];
        bool sucessful = false;
        unordered_map<int,int> tmp_map = myqueue;
        
        for(auto it = mystack.end(); it != mystack.begin(); --it)
        {
            auto tmp_it = it;
            --tmp_map[*(--tmp_it)]; //--tmp_it後就會立刻變動，而不是暫時變動
            
            if(tmp_map[x] > tmp_map[*tmp_it])
            {
                sucessful = true;
                mystack.insert(it, x);
                break;
            }
        }
        
        if(!sucessful)
            mystack.push_front(x);
    }
    
    int pop() {
        int ans = mystack.back();
        --myqueue[ans];
        mystack.pop_back();
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */