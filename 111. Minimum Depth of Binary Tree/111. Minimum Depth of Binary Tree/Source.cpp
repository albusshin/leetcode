/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        int ld = minDepth(root->left);
        int rd = minDepth(root->right);
        if (ld == 0) return 1 + rd;
        if (rd == 0) return 1 + ld;
        return 1 + min(ld, rd);
    }
};