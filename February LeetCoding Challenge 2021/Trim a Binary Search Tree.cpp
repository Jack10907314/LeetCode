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
    int lo = 0;
    int hi = 0;
    TreeNode* cut(TreeNode* root)
    {
        if(root == NULL)
            return NULL;
        //cout << root->val << endl;
        root->left = cut(root->left);
        root->right= cut(root->right);

        if(root->val > hi || root->val < lo)
        {
            
            if(root->right != NULL)
            {
                return root->right;
            }
            else if(root->left != NULL)
                return root->left;
            else
            {
                root = NULL;
                return NULL;
            }
        }
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        lo = low;
        hi = high;
        TreeNode* re = cut(root);
        if(re == root->right)
            return root->right;
        if(re == root->left)
            return root->left;
        
        return root;
    }
};