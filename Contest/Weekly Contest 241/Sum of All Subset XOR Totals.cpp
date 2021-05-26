class Solution {
public:
    int ans = 0;
    void solve(int x, vector<int>& nums, int index){
        if(index == nums.size()) return;
        ans+=x^nums[index];
        solve(x, nums, index+1);
        solve(x^nums[index], nums, index+1);
    }
    int subsetXORSum(vector<int>& nums) {
        solve(0, nums, 0);
        return ans;
    }
};