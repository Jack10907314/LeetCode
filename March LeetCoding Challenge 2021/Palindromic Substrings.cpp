class Solution {
public:
    int countSubstrings(string s) {
        int ans = s.size();
        int n = s.size();
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < n-i; ++j){
                int left = j;
                int right = j+i;
                while(left < right){
                    if(s[left] != s[right]){
                        --ans;
                        break;
                    }
                    left++;
                    right--;
                }
                ans++;
            }
        }
        return ans;
    }
};