class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int time = 1;
        while(true){
            int big = max(memory1, memory2);
            if(big < time)
                break;
            if(memory2 > memory1){
                memory2 -= time;
            }
            else{
                memory1 -= time;
            }
            time++;
        }
        
        return {time, memory1, memory2};
    }
};