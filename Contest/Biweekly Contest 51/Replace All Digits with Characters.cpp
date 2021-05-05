class Solution {
public:
    string replaceDigits(string s) {
        string ans = "";
        for(int i = 0; i < s.size(); i ++){
            if(s[i]>='a' && s[i]<='z')
                ans.push_back(s[i]);
            else{
                ans.push_back(s[i-1]+s[i]-'0');
            }
        }
        return ans;
    }
};