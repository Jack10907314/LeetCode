class Solution {
public:
    typedef pair<int, pair<int, int>> piii;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int count = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> visible(m, vector<int>(n, 0));
        priority_queue<piii, vector<piii>, greater<piii> > pq;
        pq.push(make_pair(matrix[0][0], make_pair(0,0)));
        while(!pq.empty()){
            count++;
            if(count == k)
                return pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(x < m-1){
                if(!visible[x+1][y])
                    pq.push(make_pair(matrix[x+1][y], make_pair(x+1, y)));
                visible[x+1][y] = 1;
            }
            if(y < n-1){
                if(!visible[x][y+1])
                    pq.push(make_pair(matrix[x][y+1], make_pair(x, y+1)));
                visible[x][y+1] = 1;
            }
        }
        return -1;
    }
};