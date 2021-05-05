class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int> > seat;
        
    SeatManager(int n) {
        for(int i = 0; i < n ; i++)
            seat.push(i+1);
    }
    
    int reserve() {
        int num = seat.top();
        seat.pop();
        return num;
        /*for(int i = 0 ; i < seat.size() ; ++i){
            if(seat[i] == false) {
                seat[i] = true;
                return i+1;
            }
        }
        return -1;*/
    }
    
    void unreserve(int seatNumber) {
        seat.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */