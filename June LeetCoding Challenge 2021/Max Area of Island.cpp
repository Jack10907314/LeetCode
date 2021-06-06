class Solution {
public:
    int m = 0;
    int n = 0;
    int dfs(vector<vector<int>>& grid, int x, int y){
        if(grid[x][y] == 0 || grid[x][y] == -1) return 0;
        grid[x][y] = -1;
        int count = 0;
        if(x != 0){
            count += dfs(grid, x-1, y);
        }
        if(y != 0){
            count += dfs(grid, x, y-1);
        }
        if(x != m-1){
            count += dfs(grid, x+1, y);
        }
        if(y != n-1){
            count += dfs(grid, x, y+1);
        }
        return count+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(!(grid[i][j] == 0 || grid[i][j] == -1)){
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};