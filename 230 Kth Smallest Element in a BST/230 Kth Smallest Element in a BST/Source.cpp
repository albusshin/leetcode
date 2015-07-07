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
    int k;
    int counter;
    int result;
    bool found;
public:
    Solution() {
        counter = 0;
        found = false;
    };
    
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        inorder(root);
        return result;
    }
    
    void inorder(TreeNode* root) {
        if (found) return;
        if (!root) return;
        inorder(root->left);
        counter++;
        if (counter == k) {
            result = root->val;
            found = true;
        }
        inorder(root->right);
    }
};