class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        int dp[n1+1][n2+1];
        //auto dp = vector<vector<int>>(n1+1, vector<int>(n2+1, 0));
        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                    continue;
                }
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n1][n2];
    }
};


/*class Solution {
public:
    int brute_force(int index1, int index2, string& text1, string& text2){
        if(index1 == text1.size() || index2 == text2.size())
            return 0; 
        int count = 0;
        if(text1[index1] == text2[index2])
            count = 1 + brute_force(index1+1, index2+1, text1, text2);
        else{
            count = max(brute_force(index1+1, index2, text1, text2), brute_force(index1, index2+1, text1, text2));
        }
        return count;
    }
    int longestCommonSubsequence(string text1, string text2) {
        return brute_force(0, 0, text1, text2);
    }
};*/