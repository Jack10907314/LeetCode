class Solution {
public:
    int reverse(int x) {
        vector<int> sequence;
        bool negative = false;
        long long ans = 0;
        long long y = x;
        if(x < 0)
        {
            negative = true;
            y *= -1;
        }
        while(y != 0)
        {
            sequence.push_back(y%10);
            y /= 10;
        }
        for(int i = 0 ; i < sequence.size() ; ++i)
        {
            ans += pow(10,sequence.size()-i-1)*sequence[i];
        }
        if(negative)
            ans *= -1;
        
        if(ans > INT_MAX || ans < INT_MIN)
            return 0;
        return ans;
    }
};