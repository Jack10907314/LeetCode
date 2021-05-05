class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);
        /*for(int i = 0; i < courses.size(); ++i){
            cout << courses[i][0] << "," << courses[i][1] << endl;
        }*/
        int ans = 0;
        int nowDay = 0;
        priority_queue<int, vector<int>> q;
        for(auto& v : courses){
            if(nowDay + v[0] <= v[1]){
                nowDay += v[0];
                q.push(v[0]);
                ++ans;
            }
            else{
                if(q.empty()) continue;
                if(v[0]<q.top()){
                    nowDay-=q.top();
                    q.pop();
                    nowDay += v[0];
                    q.push(v[0]);
                }
            }
        }
        /*while(!q.empty()) {
            cout << q.top() << " ";
            q.pop();
        }*/
        return ans;
    }
};