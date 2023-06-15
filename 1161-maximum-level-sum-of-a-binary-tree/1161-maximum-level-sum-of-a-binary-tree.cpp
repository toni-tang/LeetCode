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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int maxSum = INT_MIN;
        int res = 1;
        
        q.push(root);
        
        int level = 1;
        while(!q.empty()) 
        {
            int n = q.size();
            int sum = 0;
            
            for(int i = 0; i < n; i++) 
            {
                TreeNode* frontNode = q.front(); q.pop();
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
                    
                sum += frontNode->val;
            }
            
            if(sum > maxSum) 
            {
                maxSum = sum;
                res = level;
            }
            
            level++;
        }
         
        
        return res;
    }
};