class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int> s;
        int left = 0;
        int ans = 0;
        int sum = 0;
        for(int right = 0; right < nums.size(); ++right){
            while(s.find(nums[right]) != s.end()){
                s.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
            s.insert(nums[right]);
            sum += nums[right];
            ans = max(ans, sum);
        }
        return ans;
    }
};