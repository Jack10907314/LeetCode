class Solution {
public:
    int integerBreak(int n) {
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        int count3 = 0;
        int count2 = 0;
        if( (n%3) == 0 )
        {
            count3 = n/3;
        }
        else if( (n%3) == 1 )
        {
            count3 = n/3 - 1;
            count2 = 2;
        }
        else if( (n%3) == 2 )
        {
            count3 = n/3;
            count2 = 1;
        }
        return pow(3,count3) * pow(2,count2);
    }
};