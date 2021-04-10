class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vs(26,0);
        vector<int> vt(26,0);
        for(char c : s)
            vs[c-'a']++;
        for(char c : t)
            vt[c-'a']++;
        if(vs == vt)
            return true;
        return false;
    }
};