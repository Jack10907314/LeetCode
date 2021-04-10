class Solution {
public:
    static bool compare(string a, string b)
    {
        return a.size()>b.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        string contain = "";
        sort(words.begin(), words.end(), compare);
        
        for(int i = 0; i < words.size();++i)
        {
            bool whether = false;
            int point_word = 0;

            if(contain.find(words[i]+"#") != -1)
                continue;
            else
                contain += words[i]+"#";
        }

        return contain.size();
    }
};