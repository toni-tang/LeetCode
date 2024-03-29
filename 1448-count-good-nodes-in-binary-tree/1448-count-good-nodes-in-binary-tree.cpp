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
        dfs(root, root, res);
        return res;
    }
private:
    void dfs(TreeNode* node, TreeNode* prev, int& count) {
        if(!node) return;
        if(node->val >= prev->val) {
            prev = node;
            count++;
        }
        dfs(node->left, prev, count);
        dfs(node->right, prev, count);
    }
};