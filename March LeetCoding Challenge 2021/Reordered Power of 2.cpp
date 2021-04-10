class Solution {
public:
    bool reorderedPowerOf2(int N) {
        vector<int> number(10, 0);
        int count = 0;
        while(N != 0)
        {
            number[N%10]++;
            ++count;
            N/=10;
        }
        
        int num = 1;
        int num10 = pow(10, count-1);
        while(num / num10 < 10){
            if(0 < num / num10)
            {
                vector<int> number2(10, 0);
                int n = num;
                while(n != 0)
                {
                    number2[n%10]++;
                    n/=10;
                }

                if(number == number2)
                    return true;
            }
            num *= 2;
        }
        
        return false;
    }
};