class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int> map;
        for(int i = 0; i < words.size(); ++i){
            map[words[i]] = i;
        }
        for(int i = 0; i < words.size(); ++i){
            string s = words[i];
            if(s == ""){
                for(int j = 0; j < words.size(); ++j){
                    if(i != j && isPalindrome(words[j]))
                        ans.push_back({i, j});
                }
            }
            else
                for(int j = 0; j < words[i].size(); ++j){
                    string s1 = s.substr(0, j);
                    string s2 = s.substr(j);
                    if(isPalindrome(s1)){
                        string tmp = s2;
                        reverse(tmp.begin(), tmp.end());
                        if(map.count(tmp) > 0 && i != map[tmp]){
                            ans.push_back({map[tmp], i});
                        }
                    }
                    if(isPalindrome(s2)){
                        string tmp = s1;
                        reverse(tmp.begin(), tmp.end());
                        if(map.count(tmp) > 0 && i != map[tmp]){
                            ans.push_back({i, map[tmp]});
                        }
                    }
                }
        }
        return ans;
    }
    
    bool isPalindrome(string& s){
        int left = 0;
        int right = s.size()-1;
        while(left <= right){
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};