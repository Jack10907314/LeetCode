class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        dp[0] = 1;
        for(int i = 1; i <= n; ++i){
            dp[i] = 0;
            for(int k =1; k <= i ; ++k){
                dp[i] += dp[k-1] * dp[i-k];
            }
        }
        /*for(int i = 1; i <= n; ++i ){
            cout << dp[i] << " ";
        }*/
        return dp[n];
    }
};