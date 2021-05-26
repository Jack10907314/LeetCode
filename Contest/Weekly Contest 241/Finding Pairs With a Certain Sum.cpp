class FindSumPairs {
public:
    unordered_map<int, int> map1;
    unordered_map<int, int> map2;
    vector<int> mynums1;
    vector<int> mynums2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0;i < nums1.size(); ++i){
            map1[nums1[i]]++;
        }
        for(int i = 0;i < nums2.size(); ++i){
            map2[nums2[i]]++;
        }
        mynums1 = nums1;
        mynums2 = nums2;
    }
    
    void add(int index, int val) {
        map2[mynums2[index]]--;
        mynums2[index]+=val;
        map2[mynums2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for (auto& it: map1) {
            if(map2.count(tot-it.first)>0)
                ans+= map1[it.first] * map2[tot-it.first];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */