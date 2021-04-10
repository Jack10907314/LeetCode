class Solution {
public:
    vector<vector<int>> g;
    vector<int> color;
    bool dfs(int index, int dfs_color){
        color[index] = dfs_color;
        for(int next : g[index])
        {
            if(color[next] == dfs_color) return false;
            if(color[next] == 0 && !dfs(next,-1*dfs_color)) return false;
        }
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        g = graph;
        color = vector<int>(graph.size());
        for(int i = 0; i < graph.size(); ++i)
        {
            if(color[i] == 0 && !dfs(i,1)) return false;
        }
        return true;
    }
};