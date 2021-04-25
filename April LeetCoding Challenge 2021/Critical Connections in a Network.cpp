class Solution {
public:
    unordered_map<int, vector<int>> m;
    vector<vector<int>> ans;
    vector<int> map_depth;
    int dfs(int parent, int now, int depth){
        map_depth[now] = depth;
        int early_depth = depth;
        for(auto& near : m[now]){
            if(near == parent) continue;

            int near_depth = -1;
            if(map_depth[near] == -1){
                near_depth = dfs(now, near, depth+1);
            }else{
                near_depth = map_depth[near];
            }
            
            /*cout << "now: " << now << " ,near: "<< near << " ,depth now: " << depth << " ,depth_near:" << near_depth<<endl;*/
            if(near_depth > depth){
                ans.push_back({now, near});
            }
            early_depth = min(early_depth, near_depth);
            
        }
        map_depth[now] = early_depth;
        return early_depth;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for(auto& v: connections){
            m[v[0]].push_back(v[1]);
            m[v[1]].push_back(v[0]);
        }
        map_depth = vector<int>(n, -1);
        dfs(-1, 0, 0);
        return ans;
    }
};