static auto x = []() {ios_base::sync_with_stdio(false); cin.tie(NULL); return nullptr; }();
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int middle = 0;
        int left = 0;
        int right = nums.size()-1;
        while(left <= right)
        {
            middle = (left+right)/2;
            if(nums[middle] == target)
                return middle;
            else if(nums[middle] > target)
                right = middle - 1;
            else
                left = middle + 1;
        }
        return -1;
    }
};