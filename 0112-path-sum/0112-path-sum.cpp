class Solution {
public:

    bool solve(TreeNode* root, int targetSum, int sum) {

        if(root == NULL)
            return false;

        sum += root->val;

        if(root->left == NULL && root->right == NULL)
            return sum == targetSum;

        return solve(root->left, targetSum, sum) ||
               solve(root->right, targetSum, sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {

        return solve(root, targetSum, 0);
    }
};