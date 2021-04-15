class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        vector<int> flag(n,1);
        int pick = 1;
        ans.push_back(1);
        flag[0] = 0;
        for(int i = k ; i > 0 ; --i){
            if(pick > k/2+1)
                pick -= i;
            else
                pick += i;
            flag[pick-1] = 0;
            ans.push_back(pick);
        }
        for(int i = 0 ; i < n ; ++i){
            if(flag[i] == 1)
                ans.push_back(i+1);
        }
        return ans;
    }
};