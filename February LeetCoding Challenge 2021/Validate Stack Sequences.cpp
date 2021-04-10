class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int pop_p = 0;
        stack<int> s;
        for(int i = 0; i < pushed.size(); ++i)
        {
            s.push(pushed[i]);
            while(pop_p < popped.size() && s.size() > 0 && s.top() == popped[pop_p])
            {
                ++pop_p;
                s.pop();
            }
        }
        if(pop_p == popped.size())
            return true;
        return false;
    }
};