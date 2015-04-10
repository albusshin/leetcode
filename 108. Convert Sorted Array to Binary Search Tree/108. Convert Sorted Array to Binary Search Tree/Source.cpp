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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return recur(num, 0, num.size() - 1);
    }
    TreeNode *recur(vector<int> &num, int from, int to) {
        if (from > to) return nullptr;
        if (from == to) return new TreeNode(num[from]);
        int mid = (to + from) / 2;
        TreeNode* ret = new TreeNode(num[mid]);
        ret->left = recur(num, from, mid - 1);
        ret->right = recur(num, mid + 1, to);
        return ret;
    }
};