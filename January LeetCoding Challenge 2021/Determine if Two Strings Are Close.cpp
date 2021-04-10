class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        vector<int> word1_count(26,0);
        vector<int> word2_count(26,0);
        for(char x : word1)
            word1_count[x-'a']++;
        for(char x : word2)
            word2_count[x-'a']++;
        for(int i = 0 ; i < 26 ; ++i)
            if( (word1_count[i] == 0 && word2_count[i] > 0) ||
                (word1_count[i] > 0 && word2_count[i] == 0))
                return false;
        sort(word1_count.begin(),word1_count.end());
        sort(word2_count.begin(),word2_count.end());
        if(word1_count != word2_count)
            return false;
        return true;
    }
};