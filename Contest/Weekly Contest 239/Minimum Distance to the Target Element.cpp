class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = 99999999;
        for(int i = start;i<nums.size();i++){
            if(nums[i]==target) ans=min(ans,i-start);
            
        }
        for(int i = start; i >= 0;i--){
            if(nums[i]==target
)
                ans=min(ans,start-i);
        }
        return ans;
    }
};