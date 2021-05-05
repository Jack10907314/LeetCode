class Solution {
public:
    static bool cmp(vector<int>& a , vector<int>& b)
    {
        if(a[1] < b[1]) return true;
        if(a[1] > b[1]) return false;
        return a[0] <= b[0];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),cmp);
        /*for(auto v : pairs){
            cout << "[" << v[0] << "," << v[1] << "]" << endl;
        }*/
        int ans  = 1;
        int last = pairs[0][1];
        for(int i = 0 ; i < pairs.size(); ++i){
            if(pairs[i][0] > last){
                ans++;
                last = pairs[i][1];
            }
        }
        return ans;
    }
};