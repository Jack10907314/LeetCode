class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, vector<int>> map;
        vector<int> ans(k,0);
        int n  = logs.size();
        for(int i = 0 ; i < n ; ++i){
            if(map.count(logs[i][0]) <= 0){
                map[logs[i][0]].push_back(logs[i][1]);
                ans[0]++;
            }
            else{
                if( find(map[logs[i][0]].begin(), map[logs[i][0]].end(), logs[i][1]) == map[logs[i][0]].end()){
                    map[logs[i][0]].push_back(logs[i][1]);
                    ans[map[logs[i][0]].size()-1]++;
                    ans[map[logs[i][0]].size()-2]--;
                }
            }
        }

        return ans;
    }
};