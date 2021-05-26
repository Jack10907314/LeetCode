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
    int camera = 0;
    
    int buttomUP(TreeNode* node){
        if(!node) return -1;
        buttomUP(node->left);
        buttomUP(node->right);
        int children = 0;
        if(node->left){
            if(node->left->val == 0){
                node->val = 2;
                camera++;
                return -1;
            }
            children = max(children, node->left->val);
        }
        if(node->right){
            if(node->right->val == 0){
                node->val = 2;
                camera++;
                return -1;
            }
            children = max(children, node->right->val);
        }
        
        if(children == 2)
            node->val = 1;
        
        return children;
    }
    
    int minCameraCover(TreeNode* root) {
        int children = buttomUP(root);
        if(root->val == 0 && children != 2)
            camera++;
        return camera;
    }
};