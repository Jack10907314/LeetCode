class Solution {
public:
    bool isValid(string s) {
        stack<char> s_stack;
        while(s.length() != 0)
        {
            if(s[0] == '{' && s[1] == '}')
                s.erase(0,2);
            else if(s[0] == '(' && s[1] == ')')
                s.erase(0,2);
            else if(s[0] == '[' && s[1] == ']')
                s.erase(0,2);
            else if(s[0] == '{' || s[0] == '(' || s[0] == '['){
                s_stack.push(s[0]);
                s.erase(0,1);
            }
            else{
                if(s_stack.size() == 0)
                    return false;
                else if(s_stack.top() == '{' && s[0] == '}')
                {
                    s.erase(0,1);
                    s_stack.pop();
                }
                else if(s_stack.top() == '(' && s[0] == ')')
                {
                    s.erase(0,1);
                    s_stack.pop();
                }
                else if(s_stack.top() == '[' && s[0] == ']')
                {
                    s.erase(0,1);
                    s_stack.pop();
                }
                else
                    return false;
            }
        }
        
        if(s_stack.size() != 0)
            return false;
        return true;
    }
};