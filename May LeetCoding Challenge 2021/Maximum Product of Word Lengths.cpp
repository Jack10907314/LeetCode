class Solution {
public:
    inline bool check(bitset<26>& a, bitset<26>& b){
        for(int i = 0; i < 26; ++i){
            if(a[i] && b[i]) return false;
        }
        return true;
    }
    int maxProduct(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        vector<bitset<26>> m(n);
        for(int i = 0; i < n; ++i){
            for(char& c : words[i]){
                m[i][c-'a'] = 1;
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                if(check(m[i], m[j])){
                    ans = max(ans, int(words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
        
    }
};