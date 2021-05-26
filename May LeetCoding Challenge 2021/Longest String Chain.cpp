class Solution {
public:
    static bool cmp(string a , string b){
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        unordered_map<string, int> m;
        int ans = 1;
        for(string& s : words){
            m[s] = 1;
        }
        for(string& s : words){
            for(int i = 0 ; i < s.size() ; ++i){
                string tmp = s;
                tmp.erase(i, 1);
                if(m.count(tmp) > 0)
                {
                    //cout << "s: " << s << " tmp: " << tmp << endl;
                    m[s] = max(m[s], m[tmp]+1);
                    //cout << "m[s]: " << m[s] << endl;
                }
            }
            ans = max(ans, m[s]);
        }
        return ans;
    }
};