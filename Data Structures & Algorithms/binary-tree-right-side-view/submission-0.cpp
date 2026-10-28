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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> res;
        
        deque<TreeNode*> q;

        if (root != nullptr) { q.push_back(root); }

        while (!q.empty()) {

            vector<int> level;
            int window = q.size();

            for(int i=0; i<window; i++) {
                
                TreeNode* currNode = q.front();
                q.pop_front();
                level.push_back(currNode->val);

                if (currNode->left != nullptr) { q.push_back(currNode->left); }
                if (currNode->right != nullptr) { q.push_back(currNode->right); }

            }

            res.push_back(level.back());
            
        }

        return res;
        
    }
};
