class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> rotate(n, vector<char>(m, '.'));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                rotate[j][m-i-1] = box[i][j];
            }
        }
        
        for(int i = 0; i < m; ++i){
            int count = 0;
            for(int j = 0; j < n; ++j){
                if(rotate[j][i] == '#'){
                    count++;
                    rotate[j][i] = '.';
                }
                if(rotate[j][i] == '*'){
                    for(int k = 0 ; k < count ; ++k){
                        rotate[j-1-k][i] = '#';
                    }
                    count = 0;
                }
            }
            for(int k = 0 ; k < count ; ++k){
                rotate[n-1-k][i] = '#';
            }
        }
        return rotate;
    }
};