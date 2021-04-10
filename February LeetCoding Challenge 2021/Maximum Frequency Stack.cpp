class FreqStack {
public:
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> map;
    int maxfreq = 0;
    FreqStack() {
        
    }
    
    void push(int x) {
        maxfreq = max(maxfreq, ++freq[x]);
        map[freq[x]].push(x);
    }
    
    int pop() {
        int ans = map[maxfreq].top();
        map[maxfreq].pop();
        --freq[ans];
        if(map[maxfreq].size() == 0)
            --maxfreq;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */