class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int> dp(n,1);
        int ans = 1;
        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < i ; ++j){
                if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]){
                    dp[i] = max(dp[j]+1, dp[i]);
                    ans = max(ans, dp[i]);
                }
            }
        return ans;
    }
};