class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans(searchWord.size(), vector<string>());
        sort(products.begin(), products.end());
        int start = 0;
        string prefix = "";
        for(int i = 0; i < searchWord.size(); ++i){
            prefix += searchWord[i];
            start = lower_bound(products.begin()+start, products.end(), prefix) - products.begin();
            for(int j = start; j < products.size(); ++j){
                if(ans[i].size()>=3) break;
                if(!products[j].compare(0, prefix.size(), prefix)){
                    ans[i].push_back(products[j]);
                }
            }
        }
        return ans;
    }
};