class Solution {
public:
    int minOperations(int n) {
        if(n<=1) return 0;
        
        int ans = 0;
        if(n%2 == 1){
            for(int i = 0; i < n/2; ++i){
                ans += (2*(i+1));
            }
        }
        else{
            for(int i = 0; i < n/2; ++i){
                ans += (2*(i+1))-1;
            }
        }
        
        return ans;
    }
};