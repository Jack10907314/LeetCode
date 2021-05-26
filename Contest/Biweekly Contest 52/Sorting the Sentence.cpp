class Solution {
public:
    string sortSentence(string s) {
        vector<string> com = splitStr2Vec(s, " ");
        string ans = "";
        vector<string> recom(com.size(), "");
        
        for(int i = 0 ; i < com.size(); ++i){
            int index = com[i].size()-1;
            for(int j = 0; j < com[i].size(); ++j){
                if(!(com[i][index] >= '0' && com[i][index] <= '9'))
                    break;
                index--;
            }
            //cout << com[i].substr(index, com[i].size()-index) << " ";
            int where = stoi(com[i].substr(index+1, com[i].size()-index-1));

            recom[where-1] =  com[i].substr(0, index+1);
        }
        for(int i = 0; i < recom.size(); ++i)
            ans = ans + recom[i] + " ";
        ans.pop_back();
        return ans;
    }
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
    
};