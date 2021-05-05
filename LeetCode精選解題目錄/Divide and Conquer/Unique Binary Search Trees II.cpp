/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> divide(vector<int> l){
        if(l.size()==1){
            TreeNode* node = new TreeNode(l[0]+1, NULL, NULL);
            return {node};
        }
        
        vector<TreeNode*> ret;
        for(int i = 0; i < l.size(); ++i){
            vector<int> left;
            vector<int> right;
            for(int j = 0; j < i ; ++j){
                left.push_back(l[j]);
            }
            for(int j = i+1; j < l.size(); ++j){
                right.push_back(l[j]);
            }
            /*if(i == 1 && l.size() == 3){
                for(int j = 0; j < left.size() ; ++j){
                    cout << left[j] << " ";
                }
                cout << endl;
                for(int j = 0; j < right.size(); ++j){
                    cout << right[j] << " ";
                }
                cout << endl;
            }*/
            auto left_result = divide(left);
            auto right_result = divide(right);
            /*cout << left_result.size() << endl;
            cout << right_result.size() << endl;
            cout << endl;*/
            if(right.size() == 0)
                for(int j = 0; j < left_result.size(); ++j){
                    TreeNode* node = new TreeNode(l[i]+1, left_result[j], NULL);
                    ret.push_back(node);
                }
            if(left.size() == 0)
                for(int k = 0; k < right_result.size(); ++k){
                    TreeNode* node = new TreeNode(l[i]+1, NULL, right_result[k]);
                    ret.push_back(node);
                }
            for(int j = 0; j < left_result.size(); ++j){
                for(int k = 0; k < right_result.size(); ++k){
                    TreeNode* node = new TreeNode(l[i]+1, left_result[j], right_result[k]);
                    ret.push_back(node);
                }
            }
        }
        return ret;   
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<int> l;
        for(int i = 0; i < n; i++)
            l.push_back(i);
        return divide(l);
    }
};