class Solution {
public:
    int secondHighest(string s) {
        vector<int> num(10,0);
        for(char c : s)
        {
            if(c >= '0' && c <= '9')
            {
                num[c-'0']++;
            }
        }
        
        int second = 0;
        for(int i = num.size()-1 ; i >= 0 ; --i)
        {
            if(num[i] > 0)
            {
                ++second;
            }
            if(second == 2)
                return i;
        }
        return -1;
    }
};