class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        unordered_map<char,int> A_map;
        unordered_map<char,int> B_map;
        unordered_map<char,int> tmp;
        vector<string> ans;
        int count = 0;
        for(string& s : B)
        {
            for(char c : s)
            {
                tmp[c]++;
                if(tmp[c]>B_map[c])
                {
                    ++B_map[c];
                    ++count;
                }
            }
            tmp.clear();
        }

        for(string& s : A)
        {
            int tmp_count = count;
            for(char c : s)
            {
                if(B_map.count(c)>0){
                    if(tmp[c]<B_map[c]){
                        tmp[c]++;
                        tmp_count--;
                    }
                }
            }
            if(tmp_count == 0)
                ans.push_back(s);
            tmp.clear();
        }
        
        return ans;
    }
};