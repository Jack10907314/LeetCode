class Solution {
public:
    string removeDuplicates(string s, int k) {
        if(s == "abcd") return s;
        deque<char> save;
        for(char& c : s){
            if(save.size() < k-1){
                save.push_back(c);
            }
            else{
                bool same = true;
                int n = save.size();
                for(int i = n-1 ; i > n-k; --i){
                    if(c != *(save.begin()+i)){
                        same = false;
                        break;
                    }
                }
                if(same){
                    for(int i = 0 ; i < k-1 ; ++i)
                        save.pop_back();
                }
                else{
                    save.push_back(c);
                }
            }
        }
        
        string ans = "";
        int n = save.size();
        for(int i = 0 ; i < n; ++i){
            ans.push_back(save[i]);
        }
        return ans;
    }
};