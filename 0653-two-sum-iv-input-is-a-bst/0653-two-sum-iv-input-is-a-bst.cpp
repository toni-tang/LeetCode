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
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        
        unordered_set<int> s;

        TreeNode* temp = root;
        queue<TreeNode*> q;

        q.push(temp);
        while(!q.empty())
        {   
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                if(s.find(k-temp->val) != s.end()) return true;
            
                s.insert(temp->val);

                if(temp->left != NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right != NULL)
                {
                    q.push(temp->right);
                }

                q.pop();
                temp = q.front();
            }
        }

        //Time: O(N)
        //Space: O(N);
        return false;
    }
};