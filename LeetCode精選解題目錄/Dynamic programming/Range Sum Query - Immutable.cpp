class NumArray {
public:
    vector<int> mynums;
    NumArray(vector<int>& nums) {
        mynums = nums;
        for(int i = 1 ; i < nums.size() ; ++i)
        {
            mynums[i] = mynums[i-1] + mynums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if(i == 0)
            return mynums[j];
        return mynums[j] - mynums[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */