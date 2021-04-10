class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,char> m;
        for(int i = 0 ; i < order.size(); ++i){
            m[order[i]] = i+'a';
        }
        
        auto tmp = words;
        for(string& s : tmp){
            for(char& c : s){
                c = m[c];
            }
        }
        for(string& s : words){
            for(char& c : s){
                c = m[c];
            }
        }
        
        sort(tmp.begin(), tmp.end());
        
        return words == tmp;
    }
};