class Solution {
public:
    int brokenCalc(int X, int Y) {
        int count = 0;
        if(X==Y)
            return 0;
        else if(X>Y)
            return X-Y;
        else
        {
            while(Y>X)
            {
                ++count;
                if (Y % 2 == 1)
                    Y++;
                else
                    Y /= 2;
            }
        }
        return count+X-Y;
    }
};