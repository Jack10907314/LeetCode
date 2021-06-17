class Solution {
public:
    vector<string> ans;
    int n;
    void dfs(string s, int leftcount, int rightcount){
        //cout << s << endl;
        if(leftcount + rightcount == 2*n){
            ans.push_back(s);
            return;
        }
        if(leftcount > rightcount){
            if(rightcount < n){
                dfs(s+")", leftcount, rightcount+1);
            }
        }
        if(leftcount < n){
            dfs(s+"(", leftcount+1, rightcount);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        this->n = n;
        dfs("", 0, 0);
        return ans;
    }
};