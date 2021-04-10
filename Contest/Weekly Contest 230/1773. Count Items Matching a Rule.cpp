class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int look=0;
        int ans=0;
        if(ruleKey=="type")
            look=0;
        else if(ruleKey=="color")
            look=1;
        else
            look=2;
        for(int i =0;i<items.size();++i)
            if(items[i][look]==ruleValue)
                ++ans;
        return ans;
    }
};