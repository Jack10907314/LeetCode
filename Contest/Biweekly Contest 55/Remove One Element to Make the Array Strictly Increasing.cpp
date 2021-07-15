class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int mini = -1;
        bool use = false;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i]<=mini){
                if(use)
                    return false;
                else{
                    if(i > 1){
                        if(nums[i-2]>nums[i]){
                            mini = nums[i-1];
                        }
                        else{
                            mini = nums[i];
                        }
                    }
                    else{
                        mini = min(mini, nums[i]);
                    }
                    use = true;
                }
            }
            else
                mini = nums[i];
            //cout << mini << endl;
        }
        return true;
    }
};