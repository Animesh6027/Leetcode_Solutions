class Solution {
public:
    int maxSum = INT_MIN;

    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int left = max(dfs(root->left), 0);
        int right = max(dfs(root->right), 0);
        int currentPath = root->val + left + right;
        maxSum = max(maxSum, currentPath);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
