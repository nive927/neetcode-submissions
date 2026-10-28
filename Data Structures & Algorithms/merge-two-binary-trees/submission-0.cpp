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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        stack<pair<TreeNode*, TreeNode*>> s;

        if (root1 == nullptr && root2 == nullptr) return root1;

        if (root1 == nullptr) return root2;

        if (root2 == nullptr) return root1;

        s.push({root1, root2});

        while(!s.empty()) {
            auto [top1, top2] = s.top(); // both are always non-null
            s.pop();

            top1->val += top2->val;

            if(top1->left && top2->left) s.push({top1->left, top2->left});
            else if(!top1->left) top1->left = top2->left; 
            
            if(top1->right && top2->right) s.push({top1->right, top2->right});
            else if(!top1->right) top1->right = top2->right;
            
        }

        return root1;
        
        
    }
};