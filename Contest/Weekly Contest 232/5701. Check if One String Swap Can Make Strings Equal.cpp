class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int swap1 = -1;
        int swap2 = -1;
        int count = 0;
        for(int i = 0 ; i < s1.size(); ++i)
        {
            if(s1[i]!=s2[i])
            {
                if(count == 0)
                {
                    swap1 = i;
                    count++;
                }
                else if(count == 1)
                {
                    count++;
                    swap2 = i;
                }
                else
                {
                    return false;
                }
            }
        }
        if(count == 0)
            return true;
        if(count == 1)
            return false;
        if(s1[swap1] == s2[swap2] && s1[swap2] == s2[swap1])
            return true;
        return false;
    }
};