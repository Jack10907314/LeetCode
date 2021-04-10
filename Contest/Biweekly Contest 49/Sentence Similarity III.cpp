class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        auto s1 =  split(sentence1, " ");
        auto s2 =  split(sentence2, " ");
        /*for(auto s : s1)
            cout << s << endl;*/
        /*if(s2.size()==1){
            if(s2[0]==s1[0] || s2[0] == s1.back) return true;
        }
        if(s1.size()==1){
            if(s1[0]==s2.front || s1[0] == s2.back) return true;
        }*/
        
        int l1 = 0;
        int l2 = 0;
        int r1 = s1.size()-1;
        int r2 = s2.size()-1;
        bool ls = false;
        bool rs = false;
        while((l1<=r1 && l2<=r2))
        {
            if(!ls){
                if(s1[l1] == s2[l2]){
                    ++l1;
                    ++l2;
                }
                else{
                    ls = true;
                }
            }
            if(!rs){
                if(s1[r1] == s2[r2]){
                    --r1;
                    --r2;
                }
                else{
                    rs = true;
                }
            }
            if(rs && ls){
                return false;
            }
        }
        return true;
        /*if(s1.size() >= s2.size())
        {
            int li = 0;
            
            while(s2.size()!=0){
                if()
            }
        }
        else{
            
        }*/
        return true;
    }
    
    vector<string> split(const string& str, const string& delim) {
        vector<string> res;
        if("" == str) return res;
        //先将要切割的字符串从string类型转换为char*类型
        char * strs = new char[str.length() + 1] ; //不要忘了
        strcpy(strs, str.c_str()); 

        char * d = new char[delim.length() + 1];
        strcpy(d, delim.c_str());

        char *p = strtok(strs, d);
        while(p) {
            string s = p; //分割得到的字符串转换为string类型
            res.push_back(s); //存入结果数组
            p = strtok(NULL, d);
        }

        return res;
    }

};