class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long sum = 0;
        long l_limit = limit;
        long l_goal = goal;
        for(int i : nums)
            sum += i;
        if(abs(l_goal-sum) % l_limit == 0)
            return abs(l_goal-sum) / l_limit;
        else
            return abs(l_goal-sum) / l_limit + 1;

        return 0;
    }
};