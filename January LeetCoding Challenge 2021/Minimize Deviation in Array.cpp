class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; ++i)
            if(nums[i]%2 == 1)
                nums[i] *= 2;
        int mini = *min_element(nums.begin(),nums.end());
        priority_queue<int> ans;
        for(int i : nums)
            ans.push(i);
        int answer = INT_MAX;
        while(ans.top() % 2 == 0)
        {
            int maxi = ans.top();
            ans.pop();
            ans.push(maxi/2);
            mini = min(mini, maxi/2);
            answer = min(answer, ans.top()-mini);
        }
        return answer;
    }
};