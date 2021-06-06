class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.size() < 3) return 0;
        int ans = 0;
        char a = s[0];
        char b = s[1];
        char c = '!';
        for(int i = 2; i < s.size(); ++i){
            c = s[i];
            if(a != b && b != c && c != a){
                ans++;
            }
            a = b;
            b = c;
        }
        return ans;
    }
};