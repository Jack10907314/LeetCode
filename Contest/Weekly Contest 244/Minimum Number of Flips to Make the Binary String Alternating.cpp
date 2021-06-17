class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s;
        int ans1 = 0;
        int ans2 = 0;
        int ans = INT_MAX;
        
        for(int i = 0; i < n*2; ++i){
            s[i] -= '0';
            if(s[i] == i%2) ++ans1;
            else ++ans2;
            
            if(i >= n){
                if(s[i-n] == (i-n)%2) --ans1;
                else --ans2;
            }
            //cout << ans1 << " " << ans2 << endl;
            if(i >= n-1){
                ans = min({ans1, ans2, ans});
            }
        }
        
        return ans;
    }
};