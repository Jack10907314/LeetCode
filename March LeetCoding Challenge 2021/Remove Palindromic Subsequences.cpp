class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.empty()) return 0;
        string str = s;
        reverse(str.begin(),str.end());
        if(str == s) return 1;
        return 2;
    }
};