class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int,int>>> pq;
        for(int i = 0; i < arr.size(); ++i){
            int diff = abs(arr[i]-x);
            if(pq.size() > k-1){
                if(pq.top().first > diff){
                    pq.pop();
                    pq.push(make_pair(diff, i));
                }
            }
            else{
                pq.push(make_pair(diff, i));
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(arr[pq.top().second]);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};