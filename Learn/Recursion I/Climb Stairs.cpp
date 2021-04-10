class Solution {
public:
    map<int,int> remember;
    int climbStairs(int n) {
        if(n<3)
            return n;
        
        map<int,int>::iterator x=remember.find(n);
        if( x != remember.end())
            return x->second;
        
        int ans = climbStairs(n-1) + climbStairs(n-2);
        remember.insert(pair<int,int>(n,ans));
        return ans;
    }
};