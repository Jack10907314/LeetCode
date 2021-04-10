class Solution {
public:
    int numDifferentIntegers(string word) {

        vector<string> map;
        string tmp;
        bool zero_flag = false;
        string zero;
        for(char& c : word){
            if(c >= '0' && c <= '9'){
                zero.push_back(c);
                if(!(tmp.size()==0 && c == '0'))
                    tmp.push_back(c);
            }
            else{
                if(zero.size()>0)
                if(!zero_flag){
                    bool yes = true;
                    for(char& z : zero)
                        if(z!='0')
                            yes = false;
                    if(yes)
                    {
                        map.push_back("0");
                        zero_flag = true;
                    }
                }
                if(tmp.size()>0){
                    if(find(map.begin(), map.end(), tmp) == map.end())
                        map.push_back(tmp);
                }
                tmp = "";
                zero = "";
            }
        }
        if(zero.size()>0)
        if(!zero_flag){
            bool yes = true;
            for(char& z : zero)
                if(z!='0')
                    yes = false;
            if(yes)
            {
                map.push_back("0");
                zero_flag = true;
            }
        }
        if(tmp.size()>0){
            if(find(map.begin(), map.end(), tmp) == map.end())
                map.push_back(tmp);
        }
        for(string s : map)
            cout << s << endl;
        return map.size();
    }
    
};