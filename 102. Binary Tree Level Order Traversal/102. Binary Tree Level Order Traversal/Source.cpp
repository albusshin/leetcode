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
    int level;
    vector<vector<int>> vvi;
public:
    Solution() : level(-1) {};
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ret;
        recur(root);
        for (auto rite = vvi.rbegin(); rite != vvi.rend(); ++rite)
            ret.push_back(*rite);
        return ret;
    }
    void recur(TreeNode *root) {
        level++;
        if (!root){
            level--;
            return;
        }
        vector<int> vi;
        if (level + 1 > vi.size()) vvi.push_back(vi);
        vvi[level].push_back(root->val);
        recur(root->left);
        recur(root->right);
        level--;
    }
};