class Solution {
public:

    string intToRoman(int num) {
        vector<string> string_map = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> int_map = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans = "";
        
        for(int i = 0; i < int_map.size(); ++i)
        {
            while(num >= int_map[i])
            {
                num -= int_map[i];
                ans += string_map[i];
            }
        }
        return ans;
    }
};