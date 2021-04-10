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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if(!root)
            return {};
        
        vector<int> ans;
        stack<TreeNode*> stack_Tree;
        stack_Tree.push(root);
        int index = 0;
        
        while(!stack_Tree.empty()){
            TreeNode* node = stack_Tree.top();
            stack_Tree.pop();
            
            if(!node)
                continue;

            if(node->val != voyage[index++]){
                return {-1};
            }
            
            if(!node->left){
                
            }
            else if(node->left->val != voyage[index]){
                auto tmp = node->left;
                node->left = node->right;
                node->right = tmp;

                ans.push_back(node->val);
            }
            
            stack_Tree.push(node->right);
            stack_Tree.push(node->left);
        }
        return ans;
    }
};