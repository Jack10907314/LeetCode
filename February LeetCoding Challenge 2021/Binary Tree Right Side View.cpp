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
    vector<int> ans;
    void top_down(TreeNode* root, int height)
    {
        if(root == NULL)
            return;
        if(ans.size()<height+1)
            ans.push_back(root->val);
        else
            ans[height] = root->val;
        
        top_down(root->left, height+1);
        top_down(root->right, height+1);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        top_down(root, 0);
        return ans;
    }
};