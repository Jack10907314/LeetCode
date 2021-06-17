class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int, int>> pq;
        int ans = 0;
        for(int i = 0; i < boxTypes.size(); ++i){
            pq.push(make_pair(boxTypes[i][1], boxTypes[i][0]));
        }
        while(truckSize != 0 && !pq.empty()){
            int count = pq.top().second;
            int num = pq.top().first;
            cout << num << " " << count << endl;
            pq.pop();
            count = min(count, truckSize);
            truckSize -= count;
            ans += count * num;
        }
        return ans;
    }
};