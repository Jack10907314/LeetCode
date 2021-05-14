class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        //vector<int> dp(n, INT_MAX-1);
        int dp[n];
        for(int i = 0; i < n ; ++i)
            dp[i] = INT_MAX;
        dp[0] = 0;

        for(int i =0; i < n; ++i){
            for(int j = 1; j <= nums[i]; ++j){
                if(j+i < n)
                    dp[j+i] = min(dp[j+i], dp[i]+1);
            }
        }

        return dp[n-1];
    }
};