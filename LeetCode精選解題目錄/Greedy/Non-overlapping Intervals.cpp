class Solution {
public:
    static bool compare(vector<int> a, vector<int> b)
    {
        if(a[1] < b[1])
            return true;
        else if(a[1] == b[1])
            if(a[0] < b[1])
                return true;
            else
                return false;
        else
            return false;
    }
    
    bool overlap(vector<int> a, vector<int> b)
    {
        if(a[0] < b[0] && b[0] < a[1])
            return true;
        else if(a[0] < b[1] && b[1] < a[1])
            return true;
        else if(b[0] < a[0] && a[0] < b[1])
            return true;
        else if(b[0] < a[1] && a[1] < b[1])
            return true;
        else if(a[0] == b[0] && a[1] == b[1])
            return true;
        else 
            return false;
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), compare);
        int ans=0;
        int end = intervals[0][0];
        for(int i = 0; i < intervals.size(); ++i)
        {
            if(intervals[i][0] >= end)
            {
                end = intervals[i][1];
            }
            else
            {
                ++ans;
            }
        }

        return ans;
    }
};