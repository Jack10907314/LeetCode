class Solution {
public:
    bool makeEqual(vector<string>& words) {
        if(words.size() <= 1) return true; 
        int n = words.size();
        vector<int> letter(26, 0);
        for(string& s : words){
            for(char& c : s){
                letter[c-'a']++;
            }
        }
        for(int i = 0; i < letter.size(); ++i){
            if(letter[i]%n != 0){
                if(letter[i] != 0){
                    return false;
                }
            }
            //cout << letter[i] << " " ;
        }
        return true;
    }
};