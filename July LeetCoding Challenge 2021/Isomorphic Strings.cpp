class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map_s;
        unordered_map<char, char> map_t;
        int n = s.size();
        for(int i = 0; i < n ; ++i){
            if(!map_s.count(s[i])){
                map_s[s[i]] = t[i]; 
            }
            else{
                if(map_s[s[i]] != t[i])
                    return false;
            }
            
            if(!map_t.count(t[i])){
                map_t[t[i]] = s[i]; 
            }
            else{
                if(map_t[t[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
};