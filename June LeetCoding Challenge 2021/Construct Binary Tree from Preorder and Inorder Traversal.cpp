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
    int index = 0;
    TreeNode* bfs(vector<int>& preorder, vector<int>& inorder, int left, int right){
        if(left == right) return nullptr;
        auto it = find(inorder.begin(), inorder.end(), preorder[index]);
        TreeNode* node = new TreeNode(preorder[index]);
        index++;
        //cout << left << " " << right << endl;
        node->left = bfs(preorder, inorder, left, it-inorder.begin());
        node->right = bfs(preorder, inorder, it-inorder.begin()+1, right);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return bfs(preorder, inorder, 0, preorder.size());
    }
};