/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
        
    void Buttom_up(TreeNode* root, TreeNode** p, TreeNode** q)
    {
        if(*p == *q)
            return;
        if(root)
        {
            Buttom_up(root->left, p, q);
            Buttom_up(root->right, p, q);
            
            if(*p == *q)
                return;
            if(root->left == *p)
                *p = root;
            if(root->right == *p)
                *p = root;
            if(root->left == *q)
                *q = root;
            if(root->right == *q)
                *q = root;
        }
    }
        
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        Buttom_up(root, &p, &q);
        return p;
    }
};