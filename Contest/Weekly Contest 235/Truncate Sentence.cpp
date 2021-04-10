class Solution {
public:
    string truncateSentence(string s, int k) {
        auto s1 = split(s," ");
        string ans = "";
        for(int i = 0 ; i < k ; ++i){
            if(i != k-1){
                ans += s1[i]+" ";
                //ans.push_back(s1[i]);
            }
            else
                ans += s1[i];
                //ans.push_back(s1[i]);
        }
        return ans;
        
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