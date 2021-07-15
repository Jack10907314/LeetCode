class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int ans = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid2[i][j] == 0 || grid2[i][j] == -1) continue;
                queue<pair<int, int>> q;
                bool suc = true;
                q.push(make_pair(i, j));
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    if(x < 0 || y < 0 || x >= m || y >= n) continue;
                    if(grid2[x][y] == 0 || grid2[x][y] == -1) continue;
                    if(grid1[x][y] == 0) suc = false;
                    grid2[x][y] = -1;
                    q.push(make_pair(x-1, y));
                    q.push(make_pair(x+1, y));
                    q.push(make_pair(x, y-1));
                    q.push(make_pair(x, y+1));
                }
                
                if(suc) ans++;
            }
        }
        
        return ans;
    }
};