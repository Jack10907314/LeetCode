class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0;
        int begin = -1;
        int now = -1;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i]>right){
                begin = -1;
                now = -1;
            }
            else if(nums[i]>=left){
                now = i;
                if(begin == -1){
                    begin = i;
                }
            }
            else{
                if(begin == -1){
                    begin = i;
                }
            }
            
            if(begin != -1 && now - begin + 1 > 0){
                ans += now - begin + 1;
            }
            
        }
        return ans;
    }
};