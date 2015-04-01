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
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        if (!root->left && !root->right) return true;
        bool nodeBalanced = abs(treeHeight(root->left) - treeHeight(root->right)) <= 1;
        return nodeBalanced && isBalanced(root->left) && isBalanced(root->right);
    }
    int treeHeight(TreeNode *root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        return max(1 + treeHeight(root->left), 1 + treeHeight(root->right));
    }
};