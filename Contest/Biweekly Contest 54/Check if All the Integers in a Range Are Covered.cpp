class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int all[51];
        for(int i = 0; i < 51; ++i){
            /*if(i>=left && i <= right){
                all[i] = 1;
            }*/
            all[i] = 0;
        }
        for(auto& v : ranges){
            for(int i = v[0]; i <= v[1]; ++i){
                all[i] = 1;
            }
        }
        for(int i = left; i <= right; ++i){
            if(all[i] != 1) return false;
        }
        return true;
    }
};