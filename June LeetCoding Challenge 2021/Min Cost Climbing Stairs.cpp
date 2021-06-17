class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n];
        for(int i = 0; i < n; ++i){
            if(i == 1 || i == 0) dp[i] = cost[i];
            else{
                dp[i] = min(dp[i-1], dp[i-2]);
                dp[i] += cost[i];
            }
            //cout << dp[i] << " " ;
        }
        
        return min(dp[n-1], dp[n-2]);
    }
};