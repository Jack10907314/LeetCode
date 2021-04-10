class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_ending_here = 0;
        int max_so_far = 0;
            
        for (int x : nums)
        {
            max_ending_here = max(0, max_ending_here + x);
            max_so_far = max(max_so_far, max_ending_here);
        }
        
        int r_max_ending_here = 0;
        int r_max_so_far = 0;
            
        for (int x : nums)
        {
            x *= -1;
            r_max_ending_here = max(0, r_max_ending_here + x);
            r_max_so_far = max(r_max_so_far, r_max_ending_here);
        }
        
        return max(r_max_so_far,max_so_far);
    }
};