class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        if(s.size()==1)
            return {0};
        vector<int> ans;
        int left = -1;
        int right = -1;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == c)
            {
                right = i;
                break;
            }
        }
        for(int i = 0; i < s.size(); ++i)
        {
            if(left==-1)
            {
               ans.push_back(right-i); 
            }
            else
            {
                ans.push_back(min(abs(i-left),abs(right-i)));
            }
            if(s[i]==c)
            {
                left=right;
                for(int j = i+1; j < s.size(); ++j)
                {
                    if(s[j] == c)
                    {
                        right = j;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};