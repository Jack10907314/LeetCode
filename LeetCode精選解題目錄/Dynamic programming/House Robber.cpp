class Solution {
public:
    int rob(vector<int>& nums) {
        //dynamic programming
        //k = itself, when n = 1,2
        //k = max(d[n-2]+nums[n],d[n-3]+num[n]) , when n>2
        int size = nums.size();
        if(size == 0)
            return 0;
        if(size == 1)
            return nums[0];
        vector<int> d(size,0);
        for(int i = 0 ; i < size ; ++i)
        {
            if(i <= 1)
                d[i] = nums[i];
            else if(i == 2)
                d[i] = nums[i] + d[0];
            else
                d[i] = max(d[i-2]+nums[i], d[i-3]+nums[i]);
        }
        return max(d[size-2],d[size-1]);
    }
};