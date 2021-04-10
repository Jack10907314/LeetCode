class Solution {
public:
    typedef pair<int, int> pi;
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end(), greater<int>());
        //sort(B.begin(), B.end(), greater<int>());
        priority_queue<pi, vector<pi>, less<pi> > queue_B;
        for(int i = 0 ; i < B.size(); ++i){
            queue_B.push(make_pair(B[i], i));
        }
        auto A_small = A.end()-1;
        auto A_big = A.begin();
        vector<int> ans(A.size(), 0);
        
        for(int i = 0 ; i < B.size() ; ++i){
            pi b_bigest = queue_B.top(); queue_B.pop(); 
            if(b_bigest.first >= *A_big){
                ans[b_bigest.second] = *A_small;
                A_small--;
            }
            else{
                ans[b_bigest.second] = *A_big;
                A_big++;
            }
        }
        return ans;
    }
};