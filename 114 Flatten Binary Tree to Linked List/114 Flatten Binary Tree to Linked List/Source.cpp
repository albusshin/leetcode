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
    TreeNode *prev;
public:
    void flatten(TreeNode* root) {
        prev = new TreeNode(0);
        pre(root);
    }
    void pre(TreeNode* root) {
        if (!root) return;
        TreeNode *left = root->left,
                 *right = root->right;
        prev->right = root;
        prev->left = nullptr;
        prev = root;
        pre(left);
        pre(right);
    }
};