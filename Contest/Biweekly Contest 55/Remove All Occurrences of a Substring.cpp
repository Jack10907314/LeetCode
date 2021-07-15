class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";
        for(int i = 0; i < s.size(); ++i){
            ans.push_back(s[i]);
            if(ans.size() < part.size())
                continue;
            string sub = ans.substr(ans.size()-part.size());
            if(sub == part){
                for(int j = 0; j < part.size(); ++j){
                    ans.pop_back();
                }
            }

        }
        return ans;
    }
};