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
    int goodNodes(TreeNode* root) {
        int res = 0;
        dfs(root, NULL, res);
        return res;
    }
private:
    void dfs(TreeNode* node, TreeNode* prev, int& count) {
        if(!prev) {
            count++;
            prev = node;
        }
        else
        { 
            if(node && prev && node->val >= prev->val) {
                prev = node;
                count++;
            }
        }
        
        if(node->left) dfs(node->left, prev, count);
        if(node->right) dfs(node->right, prev, count);
    }
};