class NumMatrix {
public:
    int** map;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        map = new int*[m+1];
        for(int i = 0; i < m+1; ++i){
            map[i] = new int[n+1];
        }
        for(int i = 0; i < m+1; ++i){
            for(int j = 0 ; j < n+1; ++j){
                if(i == 0 || j == 0){
                    map[i][j] = 0;
                }
                else{
                    map[i][j] = matrix[i-1][j-1];
                }
            }
        }
        
        for(int j = 1 ; j < n+1; ++j){
            for(int i = 1; i < m+1; ++i){
                map[i][j] += map[i][j-1];
            }
        }
        for(int i = 1 ; i < m+1; ++i){
            for(int j = 1; j < n+1; ++j){
                map[i][j] += map[i-1][j];
            }
        }
        
        /*for(int i = 0 ; i < n+1; ++i){
            for(int j = 0; j < n+1; ++j){
                cout << map[i][j] << " ";
            }
            cout << endl;
        }*/
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return map[row2+1][col2+1] - map[row1][col2+1] - map[row2+1][col1] + map[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */