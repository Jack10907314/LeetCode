class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int pre = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(pre >= nums[i]){
                ans += pre - nums[i] + 1;
            }
            pre = max(pre+1, nums[i]);
        }
        
        return ans;
    }
};