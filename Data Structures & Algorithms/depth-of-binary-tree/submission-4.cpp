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
    int maxDepth(TreeNode* root) {

        queue<TreeNode*> q;
        TreeNode *curr = root;
        int level = 0;

        if (curr == nullptr) {
            return level;
        }

        q.push(curr);

        while (q.size() > 0) {
            int levelSize = q.size();
            for (int i=0; i<levelSize; i++) {
                curr = q.front();
                q.pop();

                if (curr->left != nullptr) {
                    q.push(curr->left);
                }

                if(curr->right != nullptr) {
                    q.push(curr->right);
                }
            }

            level++;

        }

        return level;
         
    }
};
