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
    vector<int> ret;
    stack<TreeNode*> stk;
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return ret;
        TreeNode* p = root;
        do {
            if (p) {
                stk.push(p);
                p = p->left;
            }
            else {
                if (stk.empty()) break;
                ret.push_back(stk.top()->val);
                p = stk.top()->right;
                stk.pop();
            }
        } while (true);
        return ret;
    }
};