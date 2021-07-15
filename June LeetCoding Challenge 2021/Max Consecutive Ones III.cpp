class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int count0 = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 0){
                count0++;
                while(count0 > k){
                    if(nums[left] == 0){
                        count0--;
                    }
                    left++;
                }
            }
            right++;
            ans = max(ans, right-left);
        }
        
        return ans;
    }
};