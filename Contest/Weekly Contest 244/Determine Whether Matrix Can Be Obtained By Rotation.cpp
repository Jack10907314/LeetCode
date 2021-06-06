class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int m = mat.size();
        int n = mat[0].size();
        for(int num = 0; num < 4; ++num){
            auto tmp = mat;
            
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    tmp[i][j] = mat[j][n-i-1];
                    //cout << tmp[i][j] << " ";
                }
                //cout << endl;
            }
            //cout << endl;
            mat = tmp;
            if(mat == target)
                return true;
        }
        return false;
    }
};