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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return vector<vector<int> > ();
    
        queue<TreeNode*> q;
        stack<TreeNode*> stk;
        vector<vector<int>> res;
        int levels = 1;
        
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            vector<int> temp;
            for(int i = 0; i < n; i++) {
                temp.push_back(q.front()->val);
                TreeNode* first = (levels%2 == 0) ? q.front()->right : q.front()->left;
                TreeNode* second = (levels%2 == 0) ? q.front()->left : q.front()->right;
              
                if(first) {
                    stk.push(first);
                }
                if(second) {
                    stk.push(second);
                }
                q.pop();
            }
            while(!stk.empty())
            {
                q.push(stk.top()); stk.pop();
            }
            levels++;
            res.push_back(temp);
        }
        
        return res;
    }
};