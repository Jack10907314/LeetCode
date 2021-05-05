class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return {-1,-1};
        if(nums.size() == 1)
        {
            if(nums[0] == target)
                return {0,0};
            else
                return {-1,-1};
        }
        
        vector<int> ans = {-1,-1};
        long long right = nums.size()-1;
        long long left = 0;
        long long middle = 0;
        while(left < right)
        {
            middle = (right + left)/2;
            if(nums[middle] == target)
                right = middle;
            else if(nums[middle] > target)
                right = middle-1;
            else
                left = middle+1;
        }
        if(nums[left] == target)
            ans[0] = left;

        right = nums.size()-1;
        left = 0;
        middle = 0;
        while(left < right)
        {
            middle = (right + left)/2+1;
            if(nums[middle] == target)
                left = middle;
            else if(nums[middle] > target)
                right = middle-1;
            else
                left = middle+1;
        }
        if(nums[right] == target)
            ans[1] = right;
        return ans;
        
    }
};