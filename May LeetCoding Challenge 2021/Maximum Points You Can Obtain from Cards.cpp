class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int count = 0;
        int left_index = k-1;
        int right_index = cardPoints.size()-1;
        for(int i = 0 ; i < k ; ++i){
            count += cardPoints[i];
        }
        
        int tmp = count;
        for(int i =0; i < k; ++i){
            tmp = tmp - cardPoints[left_index] + cardPoints[right_index];
            count = max(count, tmp);
            left_index--;
            right_index--;
        }
        
        return count;
    }
};