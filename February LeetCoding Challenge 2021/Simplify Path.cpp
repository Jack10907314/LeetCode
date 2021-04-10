class Solution {
public:
    vector<string> splitStr2Vec(string s, string splitSep)
    {
        vector<string> result;
        int current = 0; //最初由 0 的位置開始找
        int next = 0;
        while (next != -1)
        {
            next = s.find_first_of(splitSep, current); //尋找從current開始，出現splitSep的第一個位置(找不到則回傳-1)
            if (next != current)
            {
                string tmp = s.substr(current, next - current);
                if(!tmp.empty())  //忽略空字串(若不寫的話，尾巴都是分割符會錯)
                {
                    result.push_back(tmp);
                }
            }
            current = next + 1; //下次由 next + 1 的位置開始找起。
        }
        return result;
    }
    string simplifyPath(string path) {
        //string s = " 15,||12 ,,AB 19";
        vector<string> sep = splitStr2Vec(path, "/");
        vector<string> ans;
        string re = "";
        for (string t : sep)
        {
            cout << t << endl;
            if(t == ".")
            {
                
            }
            else if(t == "..")
            {
                if(!ans.empty())
                {
                    ans.pop_back();
                }
            }
            else
            {
                ans.push_back(t);
            }
        }
        if(ans.size()==0)
            return "/";
        for(string t : ans)
        {
            re += "/"+t;
        }
        return re;
    }
};