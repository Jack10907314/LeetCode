class Solution {
public:
    typedef pair<int, int> pii;
    typedef pair<int, pii> piii;
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<piii,vector<piii>,greater<piii>> pq;
        int m = grid.size();
        int n = grid[0].size();
        pq.push(make_pair(grid[0][0], make_pair(0,0)));
        int ans = 0;
        
        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            ans = max(ans, pq.top().first);
            pq.pop();
            if(grid[x][y] == -1) continue;
            grid[x][y] = -1;
            if(x == m-1 && y == n-1) break;
            if(x-1 >= 0)
                pq.push(make_pair(grid[x-1][y], make_pair(x-1,y)));
            if(y-1 >= 0)
                pq.push(make_pair(grid[x][y-1], make_pair(x,y-1)));
            if(x+1 <= m-1)
                pq.push(make_pair(grid[x+1][y], make_pair(x+1,y)));
            if(y+1 <= n-1)
                pq.push(make_pair(grid[x][y+1], make_pair(x,y+1)));
            //cout << x << " " << y << endl;
        }
        return ans;
    }
};