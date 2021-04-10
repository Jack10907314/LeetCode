// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==1)
            return 1;
        long long right = n;
        long long left = 1;
        while(left+1 != right)
        {
            long long middle = (left+right)/2;
            if(isBadVersion(middle))
                right = middle;
            else
                left = middle;
        }
        if(isBadVersion(left))
            return left;
        return right;
    }
};