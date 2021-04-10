class Solution {
public:
    int scoreOfParentheses(string S) {
        int ans = 0;
        stack<int> s;
        for(char c : S)
        {
            if(c == '(')
            {
                s.push(0);
            }
            else
            {
                int sum = 0;
                int num = 0;
                while( (num = s.top()) !=0)
                {
                    sum += num;
                    s.pop();
                }

                s.pop();
                if(sum == 0)
                    s.push(1);
                else
                    s.push(sum*2);
            }
        }
        
        while(!s.empty())
        {
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};