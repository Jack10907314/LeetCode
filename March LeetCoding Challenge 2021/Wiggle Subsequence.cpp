class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1)
            return 1;
        
        int count;
        int positive;
        if(nums[1] > nums[0])
        {
            count = 2;
            positive = 1;
        }
        else if(nums[1] < nums[0])
        {
            count = 2;
            positive = -1;
        }
        else
        {
            count = 1;
            positive = 0;
            
        }
        for(int i = 2 ; i < nums.size(); ++i)
        {
            if(positive==1 && nums[i] < nums[i-1])
            {
                ++count;
                positive *= -1;
            }
            else if(positive==-1 && nums[i] > nums[i-1])
            {
                ++count;
                positive *= -1;
            }
            if(positive==0 && nums[i] < nums[i-1])
            {
                ++count;
                positive = -1;
            }
            else if(positive==0 && nums[i] > nums[i-1])
            {
                ++count;
                positive = 1;
            }
        }
        
        return count;
    }
};