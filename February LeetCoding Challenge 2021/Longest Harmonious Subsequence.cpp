class Solution {
public:
    int findLHS(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        unordered_map<int, int> hashmap;
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; ++i)
        {
            hashmap[nums[i]]++;
            auto it = hashmap.find(nums[i]-1);
            if(it != hashmap.end())
            {
                int sum = hashmap[nums[i]] + it->second;
                ans = max(ans, sum);
            }
            
            it = hashmap.find(nums[i]+1);
            if(it != hashmap.end())
            {
                int sum = hashmap[nums[i]] + it->second;
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};