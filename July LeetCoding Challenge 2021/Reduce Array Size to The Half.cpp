class Solution {
public:
    int minSetSize(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int num = arr[0];
        int count = 0;
        priority_queue<int> pq;
        for(int i = 0, iend = arr.size(); i < iend; ++i){
            if(arr[i] != num){
                num = arr[i];
                pq.push(count);
                count = 1;
            }
            else{
                count++;
            }
        }
        pq.push(count);
        int half = arr.size()/2;
        count = 0;
        int ans = 0;
        while(!pq.empty()){
            count+=pq.top();
            pq.pop();
            ans++;
            if(count >= half)
                break;
        }
        return ans;
    }
};