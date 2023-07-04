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
            int prev = 0;
            for(int i = 0; i < n; i++) 
            {
                TreeNode* node = q.front(); q.pop();
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
                cout << prev << " " << node->val << endl;
                if(i > 0) 
                {
                    if(levels % 2 == 0 && (prev >= node->val || node->val % 2 == 0 ) || levels % 2 == 1 && ( prev <= node->val || node->val % 2 == 1)) 
                    {
                        return false;
                    }
                    else 
                    {
                         prev = node->val;
                    }
                }
                else 
                {
                    if(node->val % 2 == 0 && levels % 2 == 0 || node->val % 2 == 1 && levels % 2 == 1) return false;
                    prev = node->val;
                }
            }
            levels++;
        }
        
        return true;
    }
};