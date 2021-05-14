/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<TreeNode*> T;
    TreeNode* BST(int start, int end){
        if(start == end) return NULL;
        int middle = (start+end)/2;
        T[middle]->left = BST(start, middle);
        T[middle]->right = BST(middle+1, end);
        return T[middle];
    }
    TreeNode* sortedListToBST(ListNode* head) {
        while(head){
            T.push_back(new TreeNode(head->val));
            head = head->next;
        }

        return BST(0, T.size());
    }
};