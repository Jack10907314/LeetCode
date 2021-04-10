class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        //return *max_element(nums.begin(),nums.end());
        vector<int> same(*max_element(nums.begin(),nums.end())+1,0);
        int ans = 0;
        for(int i: nums)
            same[i]++;
        for(int i = 0 ; i < same.size();++i)
            if(same[i]==1)
                ans+=i;
        return ans;
    }
};