class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        
        int minnum = INT_MAX;
        int maxnum = INT_MIN;
        int left = 0;
        int right = 0;
        for(int i = 0; i < nums.size()-1; ++i)
        {
            maxnum = max(maxnum, nums[i]);
            if(nums[i] > nums[i+1])
            {
                left = i;
                break;
            }
        }
        
        for(int i = nums.size()-1; i >= 1; --i)
        {
            minnum = min(minnum, nums[i]);
            if(nums[i] < nums[i-1])
            {
                right = i;
                break;
            }
        }
        
        if(left == 0 && right == 0)
            return 0;
        maxnum = max(maxnum, *max_element(nums.begin()+left, nums.begin()+right));
        minnum = min(minnum, *min_element(nums.begin()+left, nums.begin()+right));
        
        for(int i = 0; i <= left; ++i)
        {
            if(nums[i] > minnum)
            {
                left = i;
                break;
            }
        }
        
        for(int i = nums.size()-1; i >= right; --i)
        {
            if(nums[i] < maxnum)
            {
                right = i;
                break;
            }
        }
        
        return right - left + 1;
    }
};