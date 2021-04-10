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
    TreeNode* recursive(TreeNode* root, int v, int d, int depth)
    {
        if(!root)
            return root;
        if(d == 1)
        {
            TreeNode* newRoot = new TreeNode(v, root, NULL);
            return newRoot;
        }
        if(depth == d-1)
        {
            TreeNode* newLeft = new TreeNode(v, root->left, NULL);
            TreeNode* newRight = new TreeNode(v, NULL, root->right);
            root->left = newLeft;
            root->right = newRight;
        }
        recursive(root->left, v, d, depth+1);
        recursive(root->right, v, d, depth+1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(!root)
            return root;
        TreeNode* newRoot = recursive(root, v, d, 1);
        return newRoot;
    }
};