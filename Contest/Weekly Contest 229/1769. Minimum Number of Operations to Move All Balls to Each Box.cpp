class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size(),0);
        for(int i = 0 ; i < boxes.size(); ++i)
        {
            int index_l = 0;
            int index_r = 0;
            while((i-index_l)>=0 || (i+index_r)<=boxes.size()-1)
            {
                ++index_l;
                ++index_r;
                if((i-index_l)>=0 && boxes[i-index_l] == '1')
                    ans[i]+=index_l;
                if((i+index_r)<=boxes.size()-1 && boxes[i+index_r] == '1')
                    ans[i]+=index_r;
            }
        }
        return ans;
    }
};