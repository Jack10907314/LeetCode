class Solution {
public:
    pair<int,int> setTime(int h, int i, bool start){
        if(start){
            if(i > 00 && i < 15){
                i = 15;
            }
            else if(i > 15 && i < 30){
                i = 30;
            }
            else if(i > 30 && i < 45){
                i = 45;
            }
            else if(i > 45 && i < 60){
                i = 0;
                h++;
                if(h == 24)
                    h = 0;
            }
        }
        else{
            if(i > 00 && i < 15){
                i = 0;
            }
            else if(i > 15 && i < 30){
                i = 15;
            }
            else if(i > 30 && i < 45){
                i = 30;
            }
            else if(i > 45 && i < 60){
                i = 45;
            }
        }
        
        return make_pair(h, i);
    }
    int numberOfRounds(string startTime, string finishTime) {
        int s_h = stoi(startTime.substr(0,2));
        int s_m = stoi(startTime.substr(3));
        int e_h = stoi(finishTime.substr(0,2));
        int e_m = stoi(finishTime.substr(3));
        
        int ans =0;
        if(e_h < s_h || (e_h == s_h  && e_m < s_m)){
            auto p = setTime(s_h, s_m, true);
            s_h = p.first;
            s_m = p.second;
            p = setTime(e_h, e_m, false);
            e_h = p.first;
            e_m = p.second;
            
            if(s_h == e_h && s_m == e_m) return 0;

            int tmp_h = 24;
            int tmp_m = 0;
            if(s_h == 0 && s_m == 0){
                tmp_h = 0;
            }
            while(s_h < tmp_h || (s_h == tmp_h && s_m < tmp_m)){
                s_m += 15;
                if(s_m == 60){
                    s_m = 0;
                    s_h++;
                }
                ans++;
            }
            tmp_h = 0;
            tmp_m = 0;
            while(tmp_h < e_h || (tmp_h == e_h && tmp_m < e_m)){
                tmp_m += 15;
                if(tmp_m == 60){
                    tmp_m = 0;
                    tmp_h++;
                }
                ans++;
            }
        }
        else{
            auto p = setTime(s_h, s_m, true);
            s_h = p.first;
            s_m = p.second;
            p = setTime(e_h, e_m, false);
            e_h = p.first;
            e_m = p.second;
            
            if(s_h == e_h && s_m == e_m) return 0;
            
            while(s_h < e_h || (s_h == e_h && s_m < e_m)){
                s_m += 15;
                if(s_m == 60){
                    s_m = 0;
                    s_h++;
                }
                ans++;
            }
        }

        return ans;
    }
};