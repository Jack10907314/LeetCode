class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i)
        {
            auto it = hashmap.find(target - nums[i]);
            if(it != hashmap.end())
            {
                ans = {it->second, i};
                return ans;
            }
            else
            {
                hashmap[nums[i]] = i;
            }
        }
        return ans;
    }
};