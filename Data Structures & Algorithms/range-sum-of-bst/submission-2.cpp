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
    int rangeSumBST(TreeNode* root, int low, int high) {

        stack<TreeNode*> s;
        int rsum = 0;
        
        if(root == nullptr) return 0;

        s.push(root);

        while(!s.empty()) {

            TreeNode *curr = s.top(); // only non-null nodes added into stack
            s.pop();

            if (curr->val >= low && curr->val <= high) {
                rsum += curr->val;
            }

            if (curr->val > low && curr->left) s.push(curr->left);
            if (curr->val < high && curr->right) s.push(curr->right);

        }

        return rsum;
        
    }
};