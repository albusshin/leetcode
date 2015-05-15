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
    vector<int> lpostv, rpostv, lprev, rprev, linv, rinv;
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        postorderL(root->left);
        postorderR(root->right);
        preorderL(root->left);
        preorderR(root->right);
        inorderL(root->left);
        inorderR(root->right);
        if (lpostv.size() != lpostv.size()) return false;
        if (lprev.size() != rprev.size()) return false;
        if (linv.size() != rinv.size()) return false;
        for (int i = 0; i < lpostv.size(); i++) {
            //if (lpostv[i] != rpostv[i]) return false;
            if (lprev[i] != rprev[i]) return false;
            if (linv[i] != rinv[i]) return false;
        }
        return true;
    }
    void postorderL(TreeNode *root) {
        if (!root) return;
        postorderL(root->left);
        postorderL(root->right);
        lpostv.push_back(root->val);
    }
    void postorderR(TreeNode *root) {
        if (!root) return;
        postorderR(root->right);
        postorderR(root->left);
        rpostv.push_back(root->val);
    }
    void preorderL(TreeNode *root) {
        if (!root) return;
        lprev.push_back(root->val);
        preorderL(root->left);
        preorderL(root->right);
    }
    void preorderR(TreeNode *root) {
        if (!root) return;
        rprev.push_back(root->val);
        preorderR(root->right);
        preorderR(root->left);
    }
    void inorderL(TreeNode *root) {
        if (!root) return;
        inorderL(root->left);
        linv.push_back(root->val);
        inorderL(root->right);
    }
    void inorderR(TreeNode *root) {
        if (!root) return;
        inorderR(root->right);
        rinv.push_back(root->val);
        inorderR(root->left);
    }
};