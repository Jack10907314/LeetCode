class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        int size_mat = m*n;
        if(size_mat%r != 0)
            return mat;
        if(r*c < size_mat)
            return mat;
        int row = 0, column = 0;
        int limit_c = size_mat/r;
        vector<vector<int>> ans(r, vector<int>());
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                ans[row].push_back(mat[i][j]);
                column++;
                if(column == limit_c){
                    column = 0;
                    row++;
                }
            }
        }
        return ans;
    }
};