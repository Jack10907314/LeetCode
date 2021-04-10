class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> map;
        int copy = -1;
        int disappear = -1;
        for(int i = 0 ; i < nums.size() ; ++i)
            ++map[nums[i]];
        for(int i = 0 ; i < nums.size() ; ++i)
        {
            if(map[i+1] == 2)
                copy = i+1;
            if(map[i+1] == 0)
                disappear = i+1;
        }
        return {copy, disappear};
    }
};