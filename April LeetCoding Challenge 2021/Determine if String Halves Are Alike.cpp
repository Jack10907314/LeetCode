class Solution {
public:
    bool halvesAreAlike(string s) {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int a_index = 0;
        int b_index = s.size()/2;
        int a_count = 0;
        int b_count = 0;
        for(int i = 0; i < s.size()/2; ++i){
            if(find(vowels.begin(), vowels.end(), s[a_index]) != vowels.end()){
                ++a_count;
            }
            if(find(vowels.begin(), vowels.end(), s[b_index]) != vowels.end()){
                ++b_count;
            }
            ++a_index;
            ++b_index;
        }
        return a_count == b_count;
    }
};