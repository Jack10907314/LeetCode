class Solution {
public:
    int minimumLength(string s) {
        if(s == "")
            return 0;
        if(s.size() == 1)
            return 1;
        /*while( s.size() > 1 && s.front() == s.back())
        {
            char a = s.front();
            while(s.size()!=0 && s.front() == a )
                s.erase(0,1);
            while(s.size()!=0 && s.back() == a)
                s.pop_back();
        }*/
        int l = 0;
        int r = s.size()-1;
        while(s[l] == s[r] && r-l>0)
        {
            char a = s[l];
            while(r>=l && s[l] == a)
                ++l;
            while(r>=l && s[r] == a)
                --r;
        }
        cout << "l:"<<l<<" r:"<<r<<endl;
        return r-l+1;
    }
};