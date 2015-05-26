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
    vector<stack<int> *> vsi;
    stack<int> *currstk;
public:
    int sumNumbers(TreeNode *root) {
        currstk = new stack<int>();
        dfs(root);
        int sum = 0;
        for (auto pstk : vsi) {
            stack<int> stk = *pstk;
            int times = 1;
            while (!stk.empty()) {
                sum += stk.top() * times;
                times *= 10;
                stk.pop();
            }
        }
        return sum;
    }
    void dfs(TreeNode *root) {
        if (!root) return;
        currstk->push(root->val);
        if (!root->left && !root->right) { //leaf
            vsi.push_back(currstk);
            currstk = new stack<int>(*currstk);
        }
        dfs(root->left);
        dfs(root->right);
        currstk->pop();
        return;
    }
};