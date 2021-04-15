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
    vector<int> sum;
    void recur(TreeNode* root, int depth){
        if(!root) return;
        if(sum.size()<depth+1) sum.push_back(0);
        sum[depth] += root->val;
        recur(root->left, depth+1);
        recur(root->right, depth+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        recur(root, 0);
        return sum.back();
    }
};