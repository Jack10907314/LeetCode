class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int now = 0;
        stack<int> save;
        for(auto& s : tokens){
            if(s == "*"){
                now *= save.top();
                save.pop();
            }
            else if(s == "-"){
                int tmp = save.top();
                now = tmp - now;
                save.pop();
            }
            else if(s == "+"){
                now += save.top();
                save.pop();
            }
            else if(s == "/"){
                int tmp = save.top();
                now = tmp / now;
                save.pop();
            }
            else{
                save.push(now);
                now = stoi(s);
            }
        }
        return now;
    }
};