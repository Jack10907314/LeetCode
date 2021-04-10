class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        for(int i = n; i > 0; i--)
        {
            if(i == 1)
            {
                ans.push_back('a'+k-1);
            }
            else if((i-1)*26 < k)
            {
                ans.push_back('a'+k-26*(i-1)-1);
                k = (i-1)*26;
            }
            else
            {
                ans.push_back('a');
                k = k - 1;
            }
        }
        return ans;
    }
};