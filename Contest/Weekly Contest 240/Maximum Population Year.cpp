class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        //int count = 0;
        sort(logs.begin(), logs.end());
        vector<int> count(logs.size(), 0);
        priority_queue< int, vector<int>, greater<int> > q;
        for(int i = 0; i < logs.size(); ++i){
            if(q.empty()){
                q.push(logs[i][1]);
            }
            else{
                while(!q.empty() && logs[i][0]>=q.top()){
                    q.pop();
                }
                q.push(logs[i][1]);
            }
            count[i] = q.size();
        }
        
        int maxi = count[0];
        int index = 0;
        for(int i = 1; i < count.size(); ++i){
            if(count[i] > maxi){
                maxi = count[i];
                index = i;
            }
        }
        return logs[index][0];
    }
};