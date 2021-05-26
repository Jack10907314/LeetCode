class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto& s : words){
            bool successful = true;
            unordered_map<char, char> m1;
            unordered_map<char, char> m2;
            for(int i = 0; i < s.size() ; ++i){
                if(m1.count(pattern[i]) > 0 ){
                    if(m1[pattern[i]] != s[i]){
                        successful = false;
                        break;
                    }
                }
                else{
                    m1[pattern[i]] = s[i];
                }
                if(m2.count(s[i]) > 0 ){
                    if(m2[s[i]] != pattern[i]){
                        successful = false;
                        break;
                    }
                }
                else{
                    m2[s[i]] = pattern[i];
                }
            }
            if(successful){
                ans.push_back(s);
            }
        }
        return ans;
    }
};