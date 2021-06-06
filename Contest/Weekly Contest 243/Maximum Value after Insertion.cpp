class Solution {
public:
    string maxValue(string n, int x) {
        stringstream ss;
        ss <<  x;
        string str_x = ss.str();
        string origin = n;
        bool neg = false;
        if(n[0] == '-') neg = true;
        
        if(neg){
            for(int i= 1; i < n.size(); ++i){
                if(n[i]>str_x[0]){
                    n.insert(i, str_x);
                    break;
                }
            }
        }
        else{
            for(int i= 0; i < n.size(); ++i){
                if(n[i]<str_x[0]){
                    n.insert(i, str_x);
                    break;
                }
            }
        }
        if(n == origin){
            n += str_x;
        }
        return n;

    }
};