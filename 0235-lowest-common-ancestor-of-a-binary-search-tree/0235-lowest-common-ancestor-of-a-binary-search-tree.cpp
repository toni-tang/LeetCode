/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //U: I have a binary search tree and I need to find two nodes' lowest common ancestor. The node can be a descendant of itself
        // Is there always going to be a LCA? Can p & q be the same? Are there duplicate node values? Can root be NULL?
        //M: Tree DFS
        //P: 
        if(root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        
        if(root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        
        return root;
    }
};