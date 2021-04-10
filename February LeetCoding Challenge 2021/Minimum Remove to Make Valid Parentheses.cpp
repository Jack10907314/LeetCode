class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count = 0;
        vector<int> left_ignore;
        vector<int> right_ignore;
        for(int i = 0 ; i < s.size(); ++i){
            if(s[i] == '(')
            {
                left_ignore.push_back(i);
            }
            if(s[i] == ')')
            {
                if(left_ignore.size()==0)
                {
                    right_ignore.push_back(i);
                }
                else
                {
                    left_ignore.pop_back();
                }
            }
        }
        
        vector<int> ignore;
        for(int i : left_ignore)
            ignore.push_back(i);
        for(int i : right_ignore)
            ignore.push_back(i);
        
        string ans;
        for(int i = 0 ; i < s.size() ; ++i)
        {
            if(find(ignore.begin(), ignore.end(), i) == ignore.end())
            {
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
};