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
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return false;
        queue<TreeNode*> q;
    
        q.push(root);
        
        int levels = 0;
        while(!q.empty()) 
        {
            int n = q.size();
            int prev = levels % 2 == 0 ? 0 : INT_MAX;
            
            for(int i = 0; i < n; i++) 
            {
                TreeNode* node = q.front(); q.pop();
                
                if(levels % 2 == 0 && (prev >= node->val || node->val % 2 == 0 ) || levels % 2 == 1 && ( prev <= node->val || node->val % 2 == 1)) 
                {
                    return false;
                }

                prev = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            levels++;
        }
        
        return true;
    }
};