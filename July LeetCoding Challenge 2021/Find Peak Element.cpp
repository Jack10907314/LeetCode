class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int pre = INT_MIN;
        int pre_index = -1;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] >= pre){
                pre = nums[i];
            }
            else{
                return pre_index;
            }
            pre_index++;
        }
        return nums.size()-1;
    }
};