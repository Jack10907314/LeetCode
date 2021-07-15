class Solution {
public:
    bool checkOdd(char c){
        if( c == '1' || c == '3' || c == '5' || c == '7' || c == '9' )
            return true;
        return false;
    }
    string largestOddNumber(string num) {
        int index = 0;
        bool suc = false;
        for(int i= num.size()-1; i >= 0;--i){
            if(checkOdd(num[i])){
                index = i;
                suc = true;
                break;
            }
        }
        if(!suc)
            return "";
        return num.substr(0, index+1);
    }
};