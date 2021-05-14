class Solution {
public:
    int countPrimes(int n) {
        vector<bool> map(n+1, true);
        int count = 0;
        for(int i =2; i < n; ++i){
            if(map[i] == true){
                count++;
                int tmp = 2;
                while(i*tmp <= n){
                    map[i*tmp] = false;
                    tmp++;
                }
            }
        }

        return count;
    }
};