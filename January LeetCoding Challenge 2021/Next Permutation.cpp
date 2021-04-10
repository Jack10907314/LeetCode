class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1)
            return;
        bool lowest = true;
        int index = 0;
        for(int i = nums.size()-2 ; i >= 0; --i)
            if(nums[i] < nums[i+1])
            {
                index = i;
                lowest = false;
                break;
            }
        if(lowest)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i = nums.size()-1 ; i >= index+1 ; --i)
        {
            if(nums[i] > nums[index])
            {
                swap(nums[i],nums[index]);
                reverse(nums.begin()+index+1,nums.end());
                break;
            }
        }
    }
};