#define NULL 0
using namespace std;
//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int depth;
	int now;
public:
	Solution() {depth = 1;}
    void dfs(TreeNode *node) {
		now++;
        if (node->left != NULL) {
			dfs(node->left);
		}
		if (node->right != NULL) {
			dfs(node->right);
		}
		depth = now > depth? now : depth;
		now--;
    }
    
    int maxDepth(TreeNode *root) {
		if (root == NULL) {
			return 0;
		}
        dfs(root);
		return depth;
    }
};