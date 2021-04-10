class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int i = 0 ; i < mat.size() ; ++i)
        {
            int x = i;
            int y = 0;
            vector<int> reorder;
            while(x != mat.size() && y != mat[0].size())
            {
                reorder.push_back(mat[x][y]);
                ++x;
                ++y;
            }
            sort(reorder.begin(), reorder.end());
            while(reorder.size() > 0)
            {
                --x;
                --y;
                mat[x][y] = reorder.back();
                reorder.pop_back();
            }
        }
        for(int i = 1 ; i < mat[0].size() ; ++i)
        {
            int x = 0;
            int y = i;
            vector<int> reorder;
            while(x != mat.size() && y != mat[0].size())
            {
                reorder.push_back(mat[x][y]);
                ++x;
                ++y;
            }
            sort(reorder.begin(), reorder.end());
            while(reorder.size() > 0)
            {
                --x;
                --y;
                mat[x][y] = reorder.back();
                reorder.pop_back();
            }
        }
        return mat;
    }
};