class Solution {
public:
    string customSortString(string order, string str) {
        string ans = "";
        unordered_map<char, int> map;
        for(int i = 0; i < order.size(); ++i){
            map[order[i]] = 0;
        }
        for(int i = 0; i < str.size(); ++i){
            if(map.count(str[i])){
                map[str[i]]++;
            }
            else{
                ans.push_back(str[i]);
            }
        }
        for(int i = 0; i < order.size(); ++i){
            int count = map[order[i]];
            for(int j = 0; j < count; ++j){
                ans.push_back(order[i]);
            }
        }
        return ans;
    }
};