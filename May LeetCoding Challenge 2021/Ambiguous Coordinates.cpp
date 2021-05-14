class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        vector<string> ans;
        int n = s.size()-2;
        for(int i = 1; i < n; ++i){
            vector<string> a;
            vector<string> b;
            string left = s.substr(1,i);
            string right = s.substr(i+1, n-i);
            //cout << left << " " << right << endl;
            
            for(int j = 1; j <= left.size(); ++j){
                string tmp = left;
                if(j != left.size()){
                    if(tmp.back() == '0') continue;
                    tmp.insert(j,".");
                }
                if(tmp.size()>=2 && (tmp[0] == '0' && tmp[1] != '.')) continue;
                a.push_back(tmp);
            }
            for(int j = 1; j <= right.size(); ++j){
                string tmp = right;
                if(j != right.size()){
                    if(tmp.back() == '0') continue;
                    tmp.insert(j,".");
                }
                if(tmp.size()>=2 && (tmp[0] == '0' && tmp[1] != '.')) continue;
                b.push_back(tmp);
            }
            for(int x = 0; x < a.size(); ++x){
                for(int y = 0; y < b.size(); ++y){
                    ans.push_back("(" + a[x] + ", " + b[y] + ")");
                }
            }
        }
        return ans;
    }
};