class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int nowXOR = nums[0];
        int maxi = pow(2,maximumBit)-1;
        vector<int> ans;
        ans.push_back(maxi^nowXOR);

        for(int i = 1; i < nums.size(); ++i){
            nowXOR^=nums[i];
            ans.push_back(maxi^nowXOR);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};