/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long left = 1;
        long long right = n;
        while(left <= right)
        {
            long middle = (left+right)/2;
            int re = guess(middle);
            if(re == 0)
                return middle;
            else if(re == -1)
                right = middle - 1;
            else 
                left = middle + 1;
        }
        return -1;
    }
};