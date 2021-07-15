class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(maxMove == 0) return 0;
        int mod = 1000000007;
        int dp[m][n][maxMove+1];
        for(int i = 0; i < maxMove+1; ++i){
            for(int j = 0; j < m; ++j){
                for(int k = 0; k < n; ++k){
                    dp[j][k][i] = 0;
                }
            }
        }
        
        for(int i = 1; i < maxMove+1; ++i){
            for(int x = 0; x < m; ++x){
                for(int y = 0; y < n; ++y){
                    
                    if(x != 0)
                        dp[x][y][i] = (dp[x][y][i] + dp[x-1][y][i-1])%mod;
                    else
                        dp[x][y][i]++;
                    
                    if(y != 0)
                        dp[x][y][i] = (dp[x][y][i] + dp[x][y-1][i-1])%mod;
                    else
                        dp[x][y][i]++;
                    
                    if(x != m-1)
                        dp[x][y][i] = (dp[x][y][i] + dp[x+1][y][i-1])%mod;
                    else
                        dp[x][y][i]++;
                    
                    if(y != n-1)
                        dp[x][y][i] = (dp[x][y][i] + dp[x][y+1][i-1])%mod;
                    else
                        dp[x][y][i]++;
                }
            }
        }
        
        /*for(int i = 0; i < maxMove+1; ++i){
            for(int x = 0; x < m; ++x){
                for(int y = 0; y < n; ++y){
                    cout << dp[x][y][i] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }*/
        return dp[startRow][startColumn][maxMove];
    }
};