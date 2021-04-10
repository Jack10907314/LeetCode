class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> pow3;
        for(int i = 0 ; pow(3,i) <= n; ++i)
        {
            pow3.push_back(pow(3,i));
        }
        int point = pow3.size()-1;
        while(true)
        {
            if(point<0)
                break;
            if(pow3[point]<=n)
                n -= pow3[point];

            --point;
            if(n == 0)
                return true;
        }
        return false;
    }
};