class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int first = 0;
        int second = 0;
        int target  = 0;
        
        int tmp = 0;
        for(int i = firstWord.size()-1; i >= 0; --i){
            first += pow(10, tmp) * (firstWord[i]-'a');
            tmp++;
        }
        tmp = 0;
        for(int i = secondWord.size()-1; i >= 0; --i){
            second += pow(10, tmp) * (secondWord[i]-'a');
            tmp++;
        }
        tmp = 0;
        for(int i = targetWord.size()-1; i >= 0; --i){
            target += pow(10, tmp) * (targetWord[i]-'a');
            tmp++;
        }
        return first+second == target? true:false;
    }
};