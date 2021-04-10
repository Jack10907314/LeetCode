class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1;
        int dis = INT_MAX;
        for(int i = 0; i < points.size(); ++i)
        {
            if(x == points[i][0] || y == points[i][1])
            {
                int manhattan = abs(x - points[i][0]) + abs(y - points[i][1]);
                if(manhattan < dis)
                {
                    dis = manhattan;
                    ans = i;
                }
            }
        }
    
        return ans;
    }
};