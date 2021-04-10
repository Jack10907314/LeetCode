class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int total = candyType.size()/2;
        int count = 1;
        sort(candyType.begin(), candyType.end());
        for(int i = 1 ; i < candyType.size(); ++i)
        {
            if(total == count)
                break;
            if(candyType[i-1]!=candyType[i])
                count++;
        }
        return count;
    }
};