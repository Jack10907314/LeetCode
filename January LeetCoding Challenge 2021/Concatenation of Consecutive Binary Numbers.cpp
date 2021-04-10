static const auto _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        long long mod = (long long)(1e9+7);
        for(int i = 1 ; i <= n; ++i)
        {
            int count = 0;
            int number = i;
            while(number > 0)
            {
                number =number >> 1;
                ++count;
            }
            ans = ans << count;
            ans += i;
            ans = ans % mod;
        }
        return (int)ans;
    }
};