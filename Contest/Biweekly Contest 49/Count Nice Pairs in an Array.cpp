class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        vector<int> rev;
        for(int i : nums){
            int re = 0;
            while(i!=0){
                int mod10 = i%10;
                re = re*10 + mod10;
                i /= 10;
            }
            rev.push_back(re);
        }
        
        
        long long ans = 0;

        unordered_map<int, int> map ;
        for(int i = 0 ; i < nums.size() ; ++i){
            int a = nums[i] - rev[i];
            if(map.count(a)>0){
                ans+=map[a];
                ++map[a];
            }
            else{
                ++map[a];
            }
        }
        return ans%(long)(1e9+7);
    }
};