class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int, int>> s;
        pair<int, int> top = make_pair(0, 0);
        int n = T.size();
        vector<int> ans(n, 0);

        for(int i = n-1; i >= 0; --i){
            while(T[i] >= top.first){
                if(s.empty()){
                    break;
                }
                else{
                    s.pop();
                    if(s.empty()) top = make_pair(0, 0);
                    else top = s.top();
                }
            }
            
            //cout << "top.first: " << top.first  << " top.second: " << top.second << endl;
            if(s.empty())
                ans[i] = 0;
            else
                ans[i] = top.second - i;
            
            top = make_pair(T[i], i);
            s.push(top);
        }
        return ans;
    }
};