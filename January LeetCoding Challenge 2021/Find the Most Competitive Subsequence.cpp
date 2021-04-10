class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        int remove_count = nums.size()-k;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            while(remove_count > 0 && ans.size() > 0 &&nums[i] < ans.back() )
            {
                ans.pop_back();
                remove_count--;
            }
            
            if(ans.size() < k)
                ans.push_back(nums[i]);
            else
                remove_count--;
        }
        return ans;
    }
};