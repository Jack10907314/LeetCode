class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int furthest = 0;
        priority_queue<int> q;
        
        for(int i = heights.size()-1; i > 0; --i){
            heights[i] = heights[i]-heights[i-1];
        }
        heights[0] = 0;

        int total_bricks = bricks;
        for(int& i : heights){
            if(i <= 0){
                furthest++;
                continue;
            }
            q.push(i);
            while(i > bricks){
                if(ladders == 0){
                    break;
                }
                else{
                    if(q.size() == 0) break;
                    bricks += q.top();
                    q.pop();
                    ladders--;
                }
            }
            if(i > bricks ) break;
            
            bricks -= i;
            furthest++;
        }
        return furthest-1;
    }
};