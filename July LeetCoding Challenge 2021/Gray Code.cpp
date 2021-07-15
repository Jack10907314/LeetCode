class Solution {
public:
    vector<int> ans;
    void solve(int bit, int n){
        if(bit == n) return;
        int count = ans.size()-1;
        for(int i = count; i >= 0; --i){
            ans.push_back((1<<bit) + ans[i]);
        }
        solve(bit+1, n);
    }
    vector<int> grayCode(int n) {
        ans.push_back(0);
        ans.push_back(1);
        solve(1, n);
        return ans;
    }
};