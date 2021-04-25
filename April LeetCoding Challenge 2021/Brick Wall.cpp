class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int maxi = 0;
        long total = -1;
        for(int& i : wall[0])
            total += i;
        
        if(total == 0) return wall.size();
        unordered_map<int, int> map_gap;
        
        for(auto& v : wall){
            int gap = 0;
            for(int i = 0; i < v.size()-1; ++i){
                gap+=v[i];
                map_gap[gap]++;
                maxi = max(maxi, map_gap[gap]);
            }
        }
        
        if(maxi == 0) return wall.size();
        return wall.size()-maxi;
    }
};