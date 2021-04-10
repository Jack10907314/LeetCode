class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int ans = 0;
        while(l != r)
        {
            int width = r - l;
            int length = min(height[r], height[l]);
            ans = max(ans, width*length);
            if(height[r] <= height[l])
                --r;
            else
                ++l;
        }

        return ans;
    }
};