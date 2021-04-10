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
    vector<vector<priority_queue<int, vector<int>,greater<int>>>> combine;
    int mini = 0;
    int maxi = 0;
    int height = 0;
    void bfs(TreeNode* root, int index, int h)
    {
        if(root == NULL)
            return;
        mini = min(mini, index);
        maxi = max(maxi, index);
        height = max(height,h);
        bfs(root->left, index-1, h+1);
        bfs(root->right, index+1, h+1);
    }
    
    void track(TreeNode* root, int index, int h)
    {
        if(root == NULL)
            return;
        combine[index-mini][h].push(root->val);
        track(root->left, index-1, h+1);
        track(root->right, index+1, h+1);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        bfs(root, 0, 0);
        /*cout << mini <<endl;
        cout<<maxi << endl;
        cout<<height << endl;*/
        priority_queue<int, vector<int>,greater<int>> a;
        vector<priority_queue<int, vector<int>,greater<int>>> b(height+1,a);
        vector<vector<priority_queue<int, vector<int>,greater<int>>>> c(maxi-mini+1,b);
        combine = c;
        vector<int> d;
        vector<vector<int>> ans(maxi-mini+1,d);
        track(root, 0, 0);
        for(int i = 0 ; i < combine.size() ; ++i)
            for(int j = 0 ; j < combine[i].size() ; ++j)
                while(!combine[i][j].empty())
                {
                    //cout << "i:" << i <<" j:"<<j<<" val:" <<combine[i][j].top()<<endl;
                    ans[i].push_back(combine[i][j].top());
                    combine[i][j].pop();
                }
        return ans;
    }
};