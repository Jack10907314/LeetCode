class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()==0)
            return 0;
        int sequence = 0;
        int ans = 0;
        for(int i = 1 ; i < A.size()-1; ++i){
            if(A[i] - A[i-1] == A[i+1] - A[i])
                ++sequence;
            else
                sequence = 0;
            ans+=sequence;
        }
        return ans;
    }
};