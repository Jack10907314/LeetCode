class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> check(3, false);
        for(int i = 0; i < triplets.size(); ++i){
            if(triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2])
                continue;
            if(triplets[i][0] == target[0])
                check[0] = true;
            if(triplets[i][1] == target[1])
                check[1] = true;
            if(triplets[i][2] == target[2])
                check[2] = true;
        }
        for(int i = 0 ; i < check.size(); ++i){
            if(!check[i]) return false;
        }
        return true;
    }
};