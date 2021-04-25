static vector<int> Fibonacci;
class Solution {
public:
    int fib(int n) {
        if(Fibonacci.size() < 2){
            Fibonacci.push_back(0);
            Fibonacci.push_back(1);
        }
        while(Fibonacci.size() <= n){
            Fibonacci.push_back(*(Fibonacci.end()-1) + *(Fibonacci.end()-2));
        }
        return Fibonacci[n];
    }
};