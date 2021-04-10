class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n1 = edges[0][0];
        int n2 = edges[0][1];

        int count1 = 1;
        int count2 = 1;
        for(int i = 1; i < edges.size(); ++i)
        {
            if(n1 == edges[i][0] || n1 == edges[i][1])
                count1++;
            if(n2 == edges[i][0] || n2 == edges[i][1])
                count2++;
        }
        if(count1 == edges.size())
            return n1;
        else if(count2 == edges.size())
            return n2;
        return false;
    }
};