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
        if (root == NULL) return {};
    
        queue<TreeNode*> q;
        vector<vector<int>> res;
        int levels = 0;
        
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            vector<int> temp(n);
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front(); q.pop();
                
                if(levels%2 == 0) {
                    temp[i] = node->val; 
                } else {
                    temp[n - i - 1] = node->val;
                }
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            levels++;
            res.push_back(temp);
        }
        
        return res;
    }
};