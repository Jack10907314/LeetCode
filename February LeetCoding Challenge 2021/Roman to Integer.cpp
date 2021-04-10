class Solution {
public:
    int charToInt(char c)
    {
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int ans = 0;
        ans += charToInt(s.back());
        int pre_num = ans;
        int num = 0;
        for(int i = s.size()-2 ; i >= 0 ; --i)
        {
            num = charToInt(s[i]);
            if(num < pre_num)
                ans -= num;
            else
                ans += num;
            pre_num = num;
        }
        return ans;
    }
};