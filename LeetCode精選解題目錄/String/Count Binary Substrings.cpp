class Solution {
public:
    int countBinarySubstrings(string s) {
        int count0 = 0;
        int count1 = 0;
        int ans =0 ;
        bool now0 = false;
        for(char& c : s){
            if(c == '0'){
                if(!now0){
                    count0 = 0;
                    now0 = true;
                }
                if(count1 != 0){
                    ++ans;
                    --count1;
                }
                ++count0;
            }
            else{
                if(now0){
                    count1 = 0;
                    now0 = false;
                }
                if(count0 != 0){
                    ++ans;
                    --count0;
                }
                ++count1;
            }
        }
        return ans;
    }
};