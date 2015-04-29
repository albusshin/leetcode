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
    vector<int> ret;
    int level = 0;
    vector<int> rightSideView(TreeNode *root) {
        dfs(root);
        return ret;
    }
    void dfs(TreeNode* node) {
        if (!node) return;
        level++;
        if (ret.size() < level) {
            ret.push_back(node->val);
        }
        dfs(node->right);
        dfs(node->left);
        level--;
    }
};