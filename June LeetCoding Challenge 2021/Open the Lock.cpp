class Solution {
public:
    char map[10000]; 
    inline char rotate(char c, int num){
        if(num == 1 && c == '9')
            return '0';
        if(num == -1 && c == '0')
            return '9';
        return c+num;
    }
    
    void bfs(string target){
        queue<pair<string, int>> q;
        q.push(make_pair("0000", 0));
        while(!q.empty()){
            string s = q.front().first;
            int step = q.front().second;
            q.pop();
            int i = stoi(s);
            if(map[i] != -1)
                continue;
            map[i] = step;
            if(s == target)
                return;
            //cout << s << " " << step << endl;
            for(int i = 0; i < 4; ++i){
                string tmp1 = s;
                string tmp2 = s;
                tmp1[i] = rotate(tmp1[i], 1);
                tmp2[i] = rotate(tmp2[i], -1);
                q.push(make_pair(tmp1, step+1));
                q.push(make_pair(tmp2, step+1));
            }
        }
    }
    
    int openLock(vector<string>& deadends, string target) {
        if(find(deadends.begin(), deadends.end(), "0000") != deadends.end())
            return -1;
        memset(map,-1,10000);
        for(string& s : deadends){
            int i = stoi(s);
            map[i] = -2;
        }
        bfs(target);
        int target_step = map[stoi(target)];
        if(target_step < 0) return -1;
        return target_step;
    }
};