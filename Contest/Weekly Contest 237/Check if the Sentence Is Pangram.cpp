class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> eng(26,1);
        for(char c : sentence){
            eng[c-'a']--;
        }
        for(int i : eng){
            if(i == 1) return false;
        }
        return true;
    }
};