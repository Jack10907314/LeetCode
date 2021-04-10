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
    vector<double> ans;
    vector<int> count;
    void recursive(TreeNode* root, int level)
    {
        if(!root)
            return;
        if(ans.size() == level)
        {
            ans.push_back(root->val);
            count.push_back(1);
        }
        else
        {
            ans[level] += root->val;
            count[level] += 1;
        }
        
        recursive(root->left, level+1);
        recursive(root->right, level+1);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        recursive(root, 0);
        for(int i = 0 ; i < ans.size() ; ++i)
        {
            ans[i] /= count[i];
        }
        return ans;
    }
};