class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int previous = INT_MAX - 1;
        sort(nums.begin(), nums.end());
        int ans = 0;
        int count = 1;
        for(int i = 0 ; i < nums.size() ; ++i)
        {
            if(previous+1 == nums[i])
            {
                ++count;
            }
            else if(previous == nums[i])
            {
                
            }
            else
            {
                ans = max(count, ans);
                count = 1;
            }
            previous = nums[i];
        }
        ans = max(count, ans);
        return ans;
    }
};