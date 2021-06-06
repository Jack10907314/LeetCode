class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        priority_queue<int>pq;
        for(int& i : nums){
            pq.push(i);
        }
        
        int ans = 0;
        int count = 0;
        while(pq.top()!=mini){
            int Largest= pq.top();
            while(pq.top() == Largest){
                count++;
                pq.pop();
            }
            int nextLargest = pq.top();
            ans += count;
        }
        return ans;
    }
};