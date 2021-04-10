class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        ios_base::sync_with_stdio(0),cin.tie(0);
        string ans;
        sort(d.begin(),d.end());
        for(string c : d)
        {
            int c_p = 0;
            int s_p = 0;
            while(s_p != s.size())
            {
                if(s[s_p] == c[c_p])
                    ++c_p;
                if(c_p == c.size())
                {
                    if(ans.size() < c.size())
                        ans = c;
                }
                ++s_p;
            }
            
        }
        return ans;
    }
};