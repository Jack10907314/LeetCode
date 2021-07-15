class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows, vector<int>());
        ans[0].push_back(1);
        for(int i = 0; i < numRows-1; ++i){
            ans[i+1].resize(i+2);
            for(int j = 0; j < ans[i].size(); ++j){
                ans[i+1][j] += ans[i][j];
                ans[i+1][j+1] += ans[i][j];
            }
        }
        return ans;
    }
};