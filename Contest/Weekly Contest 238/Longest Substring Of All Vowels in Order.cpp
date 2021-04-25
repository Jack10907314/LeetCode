class Solution {
public:
    int longestBeautifulSubstring(string word) {
        vector<char> low = {'a','e','i','o','u'};
        int last = 0;
        int ans = 0;
        int now = 0;
        //vector<char> tmp;
        for(char& c : word){
            if(c == low[now]){
                last++;
                //tmp.push_back(c);
            }
            else{
                if(now == 4){
                    ans = max(ans, last);
                    now = 0;
                    last = 0;
                }
                else if(last > now && c == low[now+1]){
                    now++;
                    last++;
                    //tmp.push_back(c);
                }
                else{
                    /*for(char& s:tmp)
                        cout << s;
                    tmp.clear();*/
                    now = 0;
                    last = 0;
                }
                
                if(c == low[0]) last++;
            }
            //cout << endl;
        }
        /*for(char& s:tmp)
            cout << s;*/
        if(word.back() == low[4])
            ans = max(ans, last);
        return ans;
    }
};