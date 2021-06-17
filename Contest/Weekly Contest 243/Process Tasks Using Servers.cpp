class Solution {
public:
    typedef long long ll;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        ll time = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> avai;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> unavai;
        vector<int> ans;
        for(int i = 0; i < servers.size(); ++i){
            avai.push({servers[i], i});
        }
        for(int i = 0; i < tasks.size(); ++i){
            if(i > time)
                time = i;
            if(avai.empty()){
                time = unavai.top().first;
            }
            while(!unavai.empty() && time >= unavai.top().first){
                int index = unavai.top().second;
                unavai.pop();
                avai.push({servers[index], index});
            }
            //cout << avai.top().first << endl;
            int index = avai.top().second;
            ans.push_back(index);
            unavai.push({time+tasks[i], index});
            avai.pop();
        }
        return ans;
    }
};