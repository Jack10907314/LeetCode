class Solution {
public:
    int countVowelPermutation(int n) {
        int mod = 1000000007;
        int dp[5][n];
        int ans = 5;
        for(int i = 0; i < 5; ++i){
            dp[i][0] = 1;
        }
        for(int i = 1; i < n; ++i){
            ans = 0;
            for(int j = 0; j < 5; ++j){
                dp[j][i] = 0;
                if(j == 0){
                    dp[j][i] += dp[1][i-1];
                    dp[j][i] %= mod;
                    dp[j][i] += dp[2][i-1];
                    dp[j][i] %= mod;
                    dp[j][i] += dp[4][i-1];
                    dp[j][i] %= mod;
                }
                else if(j == 1){
                    dp[j][i] += dp[0][i-1];
                    dp[j][i] %= mod;
                    dp[j][i] += dp[2][i-1];
                    dp[j][i] %= mod;
                }
                else if(j == 2){
                    dp[j][i] += dp[1][i-1];
                    dp[j][i] %= mod;
                    dp[j][i] += dp[3][i-1];
                    dp[j][i] %= mod;
                }
                else if(j == 3){
                    dp[j][i] += dp[2][i-1];
                    dp[j][i] %= mod;
                }
                else if(j == 4){
                    dp[j][i] += dp[2][i-1];
                    dp[j][i] %= mod;
                    dp[j][i] += dp[3][i-1];
                    dp[j][i] %= mod;
                }
                //cout << dp[j][i] << endl;
                ans += dp[j][i];
                ans %= mod;
            }
        }
        return ans;
    }
};