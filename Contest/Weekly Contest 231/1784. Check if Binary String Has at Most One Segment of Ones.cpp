class Solution {
public:
    bool checkOnesSegment(string s) {
        int posi1 = -1;
        for(int i = 0; i < s.size(); ++i)
        {
            if((posi1 == -1 || posi1 == i-1) && (s[i]=='1'))
            {
                posi1 = i;
            }
            else if(s[i]=='1')
                return false;
        }
        if(posi1 == -1)
            return false;
        return true;
    }
};