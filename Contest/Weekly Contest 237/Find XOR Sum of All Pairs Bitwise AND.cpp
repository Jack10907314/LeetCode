class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        vector<int> tmp;
        int ans = 0;
        int arr2_exu = 0;
        for(int j = 0 ; j < arr2.size() ; ++j){
            arr2_exu ^= arr2[j];
        }
        for(int i = 0 ; i < arr1.size(); ++i){
            ans ^= (arr1[i]&arr2_exu);
        
        }

        return ans;
    }
};