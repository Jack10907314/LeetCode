class Solution {
public:
    int minSwaps(string s) {
        int count0 = 0;
        int count1 = 0;
        int ans1 = 0;
        int ans2 = 0;
        bool is0 = false;
        for(int i = 0 ; i < s.size(); ++i){
            if(is0){
               if(s[i]=='1')
                   count1++;
            }
            else{
                if(s[i]=='0')
                    count0++;
            }
            is0 = !is0;
        }
        ans1 = count0 == count1? count0 : -1;
        
        is0 = true;
        count0 = 0;
        count1 = 0;
        for(int i = 0 ; i < s.size(); ++i){
            if(is0){
               if(s[i]=='1')
                   count1++;
            }
            else{
                if(s[i]=='0')
                    count0++;
            }
            is0 = !is0;
        }
        ans2 = count0 == count1? count0 : -1;
        
        if(ans1 == -1 && ans2 == -1)
            return -1;
        else if(ans1 == -1)
            return ans2;
        else if(ans2 == -1)
            return ans1;
        
        return min(ans1, ans2);
    }
};