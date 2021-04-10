class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> looked(n, 0);
        stack<int> key;
        looked[0] = 1;
        for(int i = 0 ; i < rooms[0].size() ; ++i)
        {
            key.push(rooms[0][i]);
        }
        while(!key.empty())
        {
            int room = key.top();
            key.pop();
            
            if(looked[room] == 0)
            {
                looked[room]++;
                for(int i = 0 ; i < rooms[room].size() ; ++i)
                {
                    key.push(rooms[room][i]);
                }
            }
        }
        for(int i = 0 ; i < n ; ++i)
        {
            if(looked[i] == 0)
                return false;
        }
        return true;
    }
};