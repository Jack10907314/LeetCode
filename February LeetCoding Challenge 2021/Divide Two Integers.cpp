class Solution {
public:
    int divide(int dividend, int divisor) {
        long a = dividend;
        long b = divisor;
        int ans = a/b;
        if((long)ans != (a/b))
            return INT_MAX;
        return ans;
    }
};