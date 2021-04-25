class Solution {
public:
    int sumBase(int n, int k) {
        vector<int> tmp;
        while(n!=0){
            tmp.push_back(n%k);
            n /= k;
        }
        int ans = 0;
        for(int i : tmp){
            ans += i;
        }
        
        return ans;
    }
};