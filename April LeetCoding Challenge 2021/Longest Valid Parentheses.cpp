class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int count = 0;
        int tmp_continue = 0;
        stack<int> sta;
        for(char& c : s){
            if(c == '('){
                sta.push(tmp_continue);
                sta.push(1);
                tmp_continue = 0;
            }
            else if(c == ')' && sta.empty()){
                tmp_continue = 0;
            }
            else if(c == ')' && sta.top()!=1){
                tmp_continue = 0;
                while(!sta.empty())
                    sta.pop();
            }
            else{
                tmp_continue+=2;
                sta.pop();
                if(!sta.empty() && sta.top()!=1){
                    tmp_continue += sta.top();
                    sta.pop();
                }
            }
            ans = max(ans, tmp_continue);
        }
        return ans;
    }
};