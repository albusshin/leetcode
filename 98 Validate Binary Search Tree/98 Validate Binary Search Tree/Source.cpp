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
public:
    bool started;
    int prevVal;
    Solution () {
        started = false;
    }
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
    bool inorder(TreeNode *node) {
        if (!node) return true;
        if (!inorder(node->left)) return false;
        int thisVal = node->val;
        if (started && prevVal >= thisVal) {
            return false;
        }
        prevVal = thisVal;
        started = true;
        if (!inorder(node->right)) return false;
        return true;
    }
};